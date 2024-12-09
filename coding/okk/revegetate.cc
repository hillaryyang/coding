#include <iostream>
using namespace std;

int n, m, g, a[151], b[151], ans[151];

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }

    for (int p = 1; p <= n; p++) { //loops through pastures
        for (g = 1; g <= 4; g++) { //loops through grasses
            bool ok = true;
            for (int c = 0; c < m; c++) { //loops thru cows
                if (b[c] == p && ans[a[c]] == g) ok = false;
            }
            if (ok) break;
        }
        ans[p] = g;
        cout << g;
    }

    cout << endl;
}