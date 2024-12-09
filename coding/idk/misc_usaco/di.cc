//http://www.usaco.org/index.php?page=viewproblem2&cpid=643
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define mp make_pair
#define ll long long
#define pb push_back
const int N = 1e5;
using namespace std;

ll n, k, mx = 0; vector<ll> a, x, y;
map<ll, ll> small, big;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin >> n >> k; 
    a.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    //for (int i : a) cout << i << " "; cout << endl;

    for (int i = n - 1; i >= 0; i--) {
        if (big.find(a[i]) == big.end()) {
            auto it = lower_bound(a.begin(), a.end(), a[i] - k);
            big[a[i]] = i + 1 - (it - a.begin());
        }
    }

    for (int i = 0; i < n; i++) {
        if (small.find(a[i]) == small.end()) {
            auto it = upper_bound(a.begin(), a.end(), a[i] + k);
            small[a[i]] = it - a.begin() - i;
        }
    }

    /*for (int i = 0; i < n; i++) x.pb(small[a[i]]);
    for (int i = 0; i < n; i++) {
        if (big[a[i]] > mx) mx = big[a[i]];
        y.pb(mx);
    }*/

    for (auto i : small) x.pb(i.second);
    for (auto i : big) {
        if (i.second > mx) mx = i.second;
        y.pb(mx);
    }
    
    //for (int i : x) cout << i << " "; cout << endl; for (int i : y) cout << i << " "; cout << endl;

    mx = 0;
    for (int i = 1; i < x.size(); i++) {
        //cout << x[i] + y[i] << endl;
        mx = max(mx, x[i] + y[i - 1]);
    }

    cout << mx << endl;
}