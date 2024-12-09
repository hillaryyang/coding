#include <iostream>
#include <algorithm>
using namespace std;

int mx, d[1000];

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> d[i];

    sort(d, d + n);

    for (int i = 0; i < n; i++) {
        int cur = 1;
        for (int j = i; j < n; j++) {
            if (i != j) {
                if (abs(d[j] - d[i]) <= k) cur++;
                else break;
            }
        }
        if (cur > mx) mx = cur;
    }

    cout << mx << endl;
}