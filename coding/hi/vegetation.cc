#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int x[200], y[200], ans[200], g;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) { cin >> x[i] >> y[i]; if (x[i] > y[i]) swap(x[i], y[i]);} 

    for (int i = 1; i <= n; i++) {
        for (g = 1; g <= 4; g++) {
            bool ok = true;
            for (int j = 0; j < m ; j++) {
                if (y[j] == i && ans[x[j]] == g) ok = false;
            }
            if (ok) break;
        }

        ans[i] = g;
        cout << g;
    }

    cout << endl;
}