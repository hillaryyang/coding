//http://www.usaco.org/index.php?page=viewproblem2&cpid=919
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb push_back
#define ll long long
const ll N = 1000;
using namespace std;

ll n, k, mx = 0, a[N][N], b[N][N], pre[N][N];

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++) {
        int in = n + 1 - i;
        for (int j = 1; j <= n; j++) {
            b[i + j - 1][in] = a[i][j]; in++;
        }
    }
    
    for (int i = 1; i <= 2*n + 10; i++) {
        for (int j = 1; j <= 2*n + 10; j++) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + b[i][j];
    }

    /*for (int i = 1; i <= 2*n + 10; i++) {
        for (int j = 1; j <= 2*n + 10; j++) cout << pre[i][j] << " "; cout << endl;
    }*/

    for (int i = 1; i <= 2 * n + 10; i++) {
        for (int j = 1; j <= 2 * n + 10; j++) {
            if (b[i][j] != (ll)0) {
                ll a = max((ll)1, i - k), b = max((ll)1, j - k), A = min(2*n + 10, i + k), B = min(2*n + 10, j + k);
                ll ans = pre[A][B] - pre[a - 1][B] - pre[A][b - 1] + pre[a - 1][b - 1];
                mx = max(mx, ans);
                //cout << A << " " << B << " " << a << " " << b << endl;
            }
        }
    }

    cout << mx << endl;
}