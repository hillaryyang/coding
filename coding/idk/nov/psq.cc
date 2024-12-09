//https://codeforces.com/problemset/problem/1881/C
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
const int N = 1010;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, ans = 0; cin >> n;
        string s;
        char a[N][N]; bool used[N][N];
        memset(used, 0, sizeof(used));

        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];
                //b[j][n - 1 - i] = s[j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!used[i][j]) {
                    int to = max(a[i][j], max(a[j][n - 1 - i], max(a[n - 1 - i][n - 1 - j], a[n - 1 - j][i])));
                    ans += 4 * to - a[i][j] - a[j][n - 1 - i] - a[n - 1 - i][n - 1 - j] - a[n - 1 - j][i];
                    used[i][j] = true; used[j][n - 1 - i] = true; used[n - 1 - i][n - 1 - j] = true; used[n - 1 - j][i] = true;
                }
            }
        }

        cout << ans << endl;
    }
}