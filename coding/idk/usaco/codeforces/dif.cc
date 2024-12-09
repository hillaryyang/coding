//https://codeforces.com/contest/1838/problem/C
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

bool prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i < x; i++) if (x % i == 0) return false;
    return true;
}

int main() {
    int t, n, m; cin >> t;

    while (t--) {
        cin >> n >> m;

        int ans[n + 5][m + 5], newans[n + 5][m + 5], tot = n * m;

        if (!prime(m)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) ans[i][j] = i * m + j + 1;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) cout << ans[i][j] << " ";
                cout << endl;
            }
        }

        else if (!prime(n)) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) ans[j][i] = i * n + j + 1;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) cout << ans[i][j] << " ";
                cout << endl;
            }
        }

        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) ans[i][j] = i * m + j + 1;
            }

            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; j++) newans[i/2][j] = ans[i][j];
            }

            for (int i = 1; i < n; i += 2) {
                for (int j = 0; j < m; j++) newans[n/2 + i/2 + 1][j] = ans[i][j];
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) cout << newans[i][j] << " ";
                cout << endl;
            }   
        }
    }
}