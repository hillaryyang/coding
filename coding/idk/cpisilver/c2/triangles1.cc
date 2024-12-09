//http://www.usaco.org/index.php?page=viewproblem2&cpid=1015
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
const ll N = 2e4 + 10;
const ll mod = 1e9 + 7;
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    ll n, x, y, ans = 0; cin >> n;
    vector<pair<ll, ll> > a;
    vector<vector<ll> > h(N), p1(N);
    vector<vector<ll> > v(N), p2(N);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x += 1e4; y += 1e4;
        a.pb(mp(x, y));
        h[y].pb(x); v[x].pb(y);
    }

    for (int i = 0; i < h.size(); i++) sort(h[i].begin(), h[i].end());
    for (int i = 0; i < v.size(); i++) sort(v[i].begin(), v[i].end());

    for (int i = 0; i < h.size(); i++) {
        if (!h[i].empty()) {
            p1[i].pb(h[i][0]);
            for (int j = 1; j < h[i].size(); j++) p1[i].pb(h[i][j] + p1[i][j - 1]); 
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (!v[i].empty()) {
            p2[i].pb(v[i][0]);
            for (int j = 1; j < v[i].size(); j++) p2[i].pb(v[i][j] + p2[i][j - 1]);
        }
    }

    for (int i = 0; i < a.size(); i++) {
        if (!h[y].empty() && !v[x].empty()) {
            ll x = a[i].first; ll y = a[i].second; ll hsum = 0, vsum = 0;
            //HORIZ
            //cout << x << " " << y << endl;

            //binary search for x in h[y]
            auto it = lower_bound(h[y].begin(), h[y].end(), x);
            ll loc = it - h[y].begin();

            //for points to the right of loc
            ll num = h[y].size() - loc - 1;
            hsum += p1[y][h[y].size() - 1] - p1[y][loc] - num * x % mod;

            //for points to the left of loc
            if (loc != 0) hsum += loc * x - p1[y][loc - 1] % mod;

            //VERT
            //binary search for x in v[y]
            it = lower_bound(v[x].begin(), v[x].end(), y);
            loc = it - v[x].begin();
            //cout << loc << endl;

            //for points above loc
            num = v[x].size() - loc - 1;
            vsum += p2[x][v[x].size() - 1] - p2[x][loc] - num * y % mod;

            //for points below loc
            if (loc != 0) vsum += loc * y - p2[x][loc - 1] % mod;

            ans += hsum * vsum % mod;
            ans %= mod;
        }
    }

    cout << ans << endl;
}