//http://www.usaco.org/index.php?page=viewproblem2&cpid=643
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
#define lb lower_bound
#define ub upper_bound
const ll N = 5e4 + 10;
using namespace std;

ll n, k, x, ans = 0;
vector<ll> a, l(N), r(N);

ll mx(ll l, ll r) {
    //returns the maximum cap # from index l to r
    ll ans = 0;

    for (ll i = l; i <= r; i++) {
        auto it1 = lower_bound(a.begin(), a.end(), a[i]), it2 = upper_bound(a.begin(), a.end(), a[i] + k);
        ll l1 = it1 - a.begin(), l2 = it2 - a.begin();
        cout << a[i] << " "<< l1 << " "<< l2 << endl;

        //cout << a[i] << " " << l2 - l1 << endl;

        if (l2 - l1 >= ans) ans = l2 - l1; 
    }
    
    return ans;
}

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}
    sort(a.begin(), a.end());
    //for(int i : a) cout << i << " "; cout << endl;

    l[a[0]] = 0;
    
    //calculate the left values
    for (int i = 1; i < n; i++) {
        //maximum of the one containing it and previous
        ll left = a[i] - k, right = a[i]; 
        auto it1 = lb(a.begin(), a.end(), left), it2 = ub(a.begin(), a.end(), right); 
        left = it1 - a.begin(), right = it2 - a.begin();
        ll val = right - left;
        //cout << val << endl;

        l[a[i]] = max(val, l[a[i - 1]]);
    }

    r[a[n - 1]] = 0;

    //calculate the right values
    for (int i = n - 2; i >= 0; i--) {
        //maximum of the one containing it and previous
        ll left = a[i], right = a[i] + k; 
        //cout << left << " " << right << endl;
        auto it1 = lb(a.begin(), a.end(), left), it2 = ub(a.begin(), a.end(), right); 
        left = it1 - a.begin(), right = it2 - a.begin();
        //cout << left << " " << right << endl;
        ll val = right - left;
        //cout << val << " " << endl;

        r[a[i]] = max(val, r[a[i + 1]]);
    }

    /*for (int i : a) cout << l[i] << " "; cout << endl;
    for (int i : a) cout << r[i] << " "; cout << endl;*/

    for (int i = 0; i < n; i++) {
        ans = max(ans, l[a[i]] + r[a[i + 1]]);
    }
    cout << ans << endl;
}