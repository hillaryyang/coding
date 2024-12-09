//https://codeforces.com/contest/1791/problem/F
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;

ll sum(ll x) {
    ll res = 0;
    while (x) {res += x % 10; x /= 10;}
    return res;
}

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, q, x, y; cin >> n >> q;

        vector<ll> a;
        set <ll> active;

        for (int i = 0; i < n; i++) {
            cin >> x; a.push_back(x);
            if (x > 9) active.insert(i);
        }

        while (q--) {
            cin >> x; 
            if (x == 1) {
                ll l, r; cin >> l >> r; l--; r--;
                auto loc = active.lower_bound(l);

                while (!active.empty()) {
                    if (*loc > r || loc == active.end()) break;
                    a[*loc] = sum(a[*loc]);
                    int temp = *loc;
                    if (a[*loc] < 10) active.erase(loc);
                    loc = active.lower_bound(temp + 1);
                }
            }

            else {cin >> x; x--; cout << a[x] << endl;}
        }
    }
}