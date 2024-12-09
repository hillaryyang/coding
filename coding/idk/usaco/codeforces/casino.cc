//https://codeforces.com/contest/1808/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
const int N = 3e5;
using namespace std;

ll t, n, m, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> m;
        ll ans = 0;
        vector<vector<ll> > te(n), c(m), pr(m);

        //inputting
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {cin >> x; te[i].push_back(x);}
        }

        //flipping
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) c[j].push_back(te[i][j]);
        }

        //sorting
        for (int i = 0; i < m; i++) sort(c[i].begin(), c[i].end());

        //prefix sums
        for (int i = 0; i < m; i++) {
            pr[i].push_back(c[i][0]);
            for (int j = 1; j < n; j++) pr[i].push_back(c[i][j] + pr[i][j - 1]);
        }

        /*for (int i = 0; i < m; i++) {
            for (int a : pr[i]) cout << a << " ";
            cout << endl;
        }*/

        //looping thru and adding to sum
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) ans += (j * c[i][j] - pr[i][j - 1]);
        }
        
        cout << ans << endl;

        c.clear(); te.clear();
    }
}