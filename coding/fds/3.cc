#include <iostream>
using namespace std;

int a[200005], ans[200005];

int main() {
    int n, k, t; 
    cin >> n >> k >> t;

    for (int i = 1; i <= k; i++) cin >> a[i];

    a[k + 1] = n;

    for (int i = 1; i <= k; i++) {
        for (int j = a[i]; j < a[i + 1]; j++) {
            int curshift = j - a[i];
            int dif = a[i + 1] - a[i];
            int newshift = (curshift - t) % dif;
            newshift = (newshift + dif) % dif;

            ans[(a[i] + newshift + t) % n] = j;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << endl;
}