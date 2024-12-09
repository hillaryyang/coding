//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb push_back
#define ll long long
using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    ll n, x, mx = 0; cin >> n;
    vector<ll> id, pre;

    for (int i = 0; i < n; i++) {cin >> x; id.pb(x);}

    pre.pb(id[0]); 
    for (int i = 1; i < n; i++) pre.pb(pre[i - 1] + id[i]);

    //for (ll i : pre) m.pb(i % 7);
    //for (ll i : pre) cout << i << " "; cout << endl;

    vector<vector<ll> > m(7);
    for (int i = 0; i < pre.size(); i++) m[pre[i] % 7].pb(i);

    for (int i = 0; i < 7; i++) {
        if (!m[i].empty()) mx = max(mx, m[i].back() - m[i][0]);
    }

    cout << mx << endl;
}