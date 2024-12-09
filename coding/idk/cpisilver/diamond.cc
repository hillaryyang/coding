//http://www.usaco.org/index.php?page=viewproblem2&cpid=643
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

ll n, k, x, mx1 = 0, lmx = 0, rmx = 0, d, u; 
vector<ll> a;

ll maxdiamond(ll l, ll r) {
    //returns the maximum cap # from index l to r
    ll ans = 0;

    for (ll i = l; i < r; i++) {
        auto it1 = lower_bound(a.begin(), a.end(), a[i]), it2 = upper_bound(a.begin(), a.end(), a[i] + k);
        ll l1 = it1 - a.begin(), l2 = it2 - a.begin();

        //cout << a[i] << " " << l2 - l1 << endl;

        if (l2 - l1 >= ans) {
            //cout << a[i] << " " << l2 - l1 << endl;
            ans = l2 - l1; 
            if (l == 0 && r == n) {d = a[i]; u = a[i] + k;}
        }
    }
    
    return ans;
}

int main() {
    freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}
    sort(a.begin(), a.end());

    //for (int i : a) cout << i << " "; cout << endl;

    //first cap from left
    mx1 = maxdiamond(0, n);

    //second cap left
    auto it = upper_bound(a.begin(), a.end(), d - 1 - k); ll loc = it - a.begin();
    lmx = maxdiamond(0, loc);

    //second cap right
    it = lower_bound(a.begin(), a.end(), u + 1); loc = it - a.begin();
    rmx = maxdiamond(loc, n);

    ll ans1 = mx1 + max(lmx, rmx);

    ll mx2 = 0;
    //first cap 
    for (ll i = n - 1; i >= 0; i--) {
        auto it1 = upper_bound(a.begin(), a.end(), a[i]), it2 = lower_bound(a.begin(), a.end(), a[i] - k);
        ll l1 = it1 - a.begin(), l2 = it2 - a.begin();

        //cout << a[i] << " " << l1 - l2 << endl;

        if (l1 - l2 >= mx2) {mx2 = l1 - l2; d = a[i] - k; u = a[i];}
    }

    //second cap left
    it = upper_bound(a.begin(), a.end(), d - 1 - k); loc = it - a.begin();
    lmx = maxdiamond(0, loc);

    //second cap right
    it = lower_bound(a.begin(), a.end(), u + 1); loc = it - a.begin();
    rmx = maxdiamond(loc, n);

    ll ans2 = mx2 + max(lmx, rmx);

    cout << max(ans1, ans2) << endl;
}