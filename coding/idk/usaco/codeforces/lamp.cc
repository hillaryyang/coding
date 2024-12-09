//http://www.usaco.org/index.php?page=viewproblem2&cpid=643
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, x, y; cin >> n;
        vector<vector<ll> > a(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> x >> y; a[x].push_back(y);
        }

        ll ct = 0;
        for (ll i = 1; i <= n; i++) {
            ll b = min(i, (ll) a[i].size());
            if (b != 0) {
                sort(a[i].begin(), a[i].end(), greater<int>());
                for (int j = 0; j < b; j++) ct += a[i][j];
            }
        }

        cout << ct << endl;
    }
}