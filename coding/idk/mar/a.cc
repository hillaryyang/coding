#include <iostream>
using namespace std;

int n, k, t, cycles, a[200000], cur[200000], temp[200000], original[200000];

void rot() {
    bool flag;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < k; j++) {
            cur[a[(j + 1) % k]] = temp[a[j]];
        }
        for (int k = 0; k < n; k++) temp[k] = cur[k];

        for (int j = 0; j < k; j++) a[j] = (a[j] + 1) % n;
    }
}

int main() {   
    cin >> n >> k >> t;

    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cur[i] = i;
    for (int i = 0; i < n; i++) {temp[i] = cur[i]; original[i] = cur[i]; }

    rot();

    for (int i = 0; i < n - 1; i++) cout << cur[i] << " ";
    cout << cur[n - 1] << endl;
}
