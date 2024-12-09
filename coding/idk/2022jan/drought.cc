//http://www.usaco.org/index.php?page=viewproblem2&cpid=1181
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

ll solve(vector<ll> a, ll n) {
    ll ct = 0;
    if (n == 1) return 0;
    if (a[0] > a[1] || a[n - 1] > a[n - 2]) return -1;
    
    //try to make each element equal to or less than the one before it
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            ll dif = a[i] - a[i - 1];
            a[i] -= dif; a[i + 1] -= dif; ct += 2 * dif;
            if (a[i] < 0 || a[i + 1] < 0) return -1;
        }
    }

    //for (int i : a) cout << i << " "; cout << endl;

    //try to make each element equal 
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            ll dif = a[i] - a[i + 1];
            a[i] -= dif; a[i - 1] -= dif; ct += 2 * dif;
            if (a[i] < 0 || a[i - 1] < 0) return -1;
        }
    }
    //for (int i : a) cout << i << " "; cout << endl;
    //check if they're all equal
    for (ll i : a) if (i != a[0]) return -1;

    return ct;
}

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, x; vector<ll> a;

        cin >> n;
        for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

        cout << solve(a, n) << endl;
    }
}