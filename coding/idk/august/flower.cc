//https://codeforces.com/contest/1862/problem/C
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 5e6 + 10;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, x; cin >> n;
        vector<ll> a, b;

        for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

        if (a[0] != n) {cout << "NO" << endl; continue;}

        reverse(a.begin(), a.end());

        for (int i = 1; i <= n; i++) {
            auto it = lower_bound(a.begin(), a.end(), i);
            int x = it - a.begin(); 
            b.pb(n - x);
        }
        reverse(b.begin(), b.end());

        bool ok = true;
        for (int i = 0; i < n; i++) if (a[i] != b[i]) ok = false;

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}