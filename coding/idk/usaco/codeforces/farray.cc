//https://codeforces.com/problemset/problem/1793/B
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;
    
    while (t--) {
        ll x, y, ans; cin >> x >> y;

        ans = 2*(x - y);

        cout << ans << endl;

        for (ll i = y; i <= x; i++) cout << i << " ";
        for (ll i = x - 1; i > y; i--) cout << i << " ";
        cout << endl;
    }
}