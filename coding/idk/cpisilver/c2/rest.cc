//https://cses.fi/problemset/task/1619
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main() {
    ll n, x, y; cin >> n;
    vector<pair<ll, ll> > a;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a.pb(mp(x, 1)); a.pb(mp(y, -1));
    }

    sort(a.begin(), a.end());

    ll cur = 0, mx = 0;
    for (auto i : a) {
        cur += i.second;
        mx = max(mx, cur);
    }

    cout << mx << endl;
}