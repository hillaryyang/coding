//https://codeforces.com/contest/1857/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, x; cin >> n;
        vector<ll> b(n * (n - 1)/2), ans;

        for (int i = 0; i < n * (n - 1)/2; i++) cin >> b[i];

        sort(b.begin(), b.end());

        ll cur = 0;
        for (int i = n - 1; i >= 1; i--) {
            //cout << cur << endl;
            ans.push_back(b[cur]);
            cur += i;
        } ans.push_back(ans.back());

        for (ll i : ans) cout << i << " "; cout << endl;
    }
}