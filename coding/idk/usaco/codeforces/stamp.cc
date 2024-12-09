#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

char c[22][22], stamp[22][22], temp[22][22];

int t, n, k;

bool ok (int a, int b) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) if (stamp[i][j] == '*' && c[i + a][j + b] == '.') return false;
    }

    return true;
}

void rot() {
    char ne[22][22];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) ne[i][j] = stamp[i][j];
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            stamp[j][k - i - 1] = ne[i][j];
        }
    }
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        memset(temp, '.', sizeof(temp));

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) c[i][j] = s[j];
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            string s; cin >> s;
            for (int j = 0; j < k; j++) stamp[i][j] = s[j];
        }

        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {
                for (int r = 0; r < 4; r++) {
                    rot(); 

                    /*for (int l = 0; l < k; l++) {
                        for (int m = 0; m < k; m++) cout << stamp[l][m];
                        cout << endl;
                    }*/

                    if (ok(i, j)) {
                        for (int l = 0; l < k; l++) {
                            for (int m = 0; m < k; m++) {
                                if (stamp[l][m] == '*') temp[i + l][j + m] = '*';
                            }
                        }
                    }
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] != c[i][j]) {ok = false; break;}
            }
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}