//https://codeforces.com/contest/1780/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, a[200010], sum = 0, mx = 0; cin >> n;
        vector<ll> pref;
        memset(a, 0, sizeof(a));

        for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}

        pref.push_back(a[0]);
        for (int i = 1; i < n; i++) pref.push_back(pref[i - 1] + a[i]);

        //for (int i : pref) cout << i << " "; cout << endl;

        for (int i = 0; i < n - 1; i++) {
            mx = max(mx, gcd(pref[i], sum - pref[i]));
        }

        cout << mx << endl;
    }
}