//http://www.usaco.org/index.php?page=viewproblem2&cpid=490
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set> 
const int N = 5e4 + 10;
#define ll long long
using namespace std;

vector<pair<ll, bool> > c;
string ss;
ll n, a, b, x, ans;

int main() {
    freopen("learning.in", "r", stdin);
    freopen("learning.out", "w", stdout);

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> ss >> x;
        if (ss == "S") c.push_back(make_pair(x, 1));
        else c.push_back(make_pair(x, 0));
    }

    ll mx = 1e10;
    c.push_back(make_pair(-mx, 0));
    c.push_back(make_pair(mx, 0));

    sort(c.begin(), c.end());

    for (int i = 0; i < c.size() - 1; i++) {
        ll l = c[i].first, r = c[i + 1].first, m = (l + r)/2;

        if (c[i].second == 1) ans += max(min(m, b) - max(l + 1, a) + 1, (ll)0);
        if (c[i + 1].second == 1) ans += max(min(r, b) - max(m + 1, a) + 1, (ll)0);
        if ((l % 2) == (r % 2) && m >= a && m <= b && c[i].second == 0 && c[i + 1].second == 1) ans++;
    }

    cout << ans << endl;
}