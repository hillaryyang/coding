//https://codeforces.com/contest/1851/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main() {
    ll t, n, x; cin >> t;

    while (t--) {
        vector<ll> a, s;

        cin >> n; 
        for (int i = 0; i < n; i++) {cin >> x; a.pb(x); s.pb(x);}

        sort(s.begin(), s.end());

        bool ok = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] % 2 != a[i] % 2) {ok = false; break;}
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}