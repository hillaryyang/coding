//https://codeforces.com/contest/1826/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll t, n, x; 
vector<ll> a, dif;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll find() {
    ll res = dif[0];
    for (int i = 1; i < dif.size(); i++) {
        res = gcd(dif[i], res); if (res == 1) return 1;
    }

    return res;
}

bool check() {
    for (int i = 0; i < n; i++) if (a[i] != a[n - i - 1]) return false;

    return true;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        for (int i = 0; i <= n/2; i++) {dif.push_back(abs(a[n - i - 1] - a[i]));}

        if (check()) cout << 0 << endl;
        else cout << find() << endl;

        a.clear(); dif.clear();
    }
}