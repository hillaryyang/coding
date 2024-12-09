#include <iostream>
#include <vector>
#define pb push_back
#define ll long long
using namespace std;

int main() {
    ll n, q, x; cin >> n >> q;
    vector<ll> a, pre;

    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

    pre.pb(0); pre.pb(a[0]);
    for (int i = 1; i < n; i++) pre.pb(pre[i] + a[i]);

    while (q--) {
        ll l, r; cin >> l >> r;
        cout << pre[r] - pre[l] << endl;
        //cout << pre[r] - pre[l - 1] << endl;
    }
}