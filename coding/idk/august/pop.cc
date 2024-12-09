//https://codeforces.com/problemset/problem/1857/E
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 2e5 + 10;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, x; cin >> n;
        vector<ll> a, pref, temp;
        map<ll, ll> ans;

        a.pb(0); temp.pb(0);
        for (int i = 0; i < n; i++) {cin >> x; a.pb(x); temp.pb(x);}

        sort(a.begin(), a.end());
        
        pref.pb(0); pref.pb(a[1]);
        for (int i = 2; i <= n; i++) pref.pb(pref[i - 1] + a[i]);

        //for (ll i : pref) cout << i << " "; cout << endl;
        //for (ll i : a) cout << i << " "; cout << endl;

        for (int i = 1; i <= n; i++) {
            ans[a[i]] = a[i] * (i - 1) + i - 1 - pref[i - 1] + pref[n] - pref[i] + (n - i) * (1 - a[i]) + 1;
            //cout << a[i] << " " << a[i] * (i - 1) + i - 1 - pref[i - 1] << " " << pref[n] - pref[i] + (n - i) * (1 - a[i]) << endl;
        }

        for (int i = 1; i <= n; i++) cout << ans[temp[i]] << " "; cout << endl;
    }
}