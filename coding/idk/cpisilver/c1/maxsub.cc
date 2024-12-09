//https://cses.fi/problemset/task/1643/
#include <iostream>
#include <vector>
#define pb push_back
#define ll long long
using namespace std;

int main() {
    ll n, x; cin >> n;
    vector<ll> a, pre;
    
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

    pre.pb(0); pre.pb(a[0]);
    for (int i = 1; i < n; i++) pre.pb(pre[i] + a[i]);

   // for (int i : pre) cout << i << " "; cout << endl;

    ll mx = a[0], mn = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, pre[i] - mn);
        if (pre[i] < mn) mn = pre[i];

       // cout << i << " " << mn << " " << mx << endl;
    }

    cout << mx << endl;
}