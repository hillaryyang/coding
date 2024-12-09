//https://atcoder.jp/contests/abc125/tasks/abc125_c
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb push_back
#define ll long long
const int N = 1e5 + 10;
using namespace std;

int gcd(int a, int b) {
    if (b) return gcd(b, a % b);
    else return a;
}

int main() {
    ll n, x, l[N], r[N], ans, mx = 0; vector<ll> a;
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

    l[0] = 0; l[1] = a[0];
    for (int i = 2; i < n; i++) l[i] = gcd(l[i - 1], a[i - 1]);

    r[n - 1] = 0; r[n - 2] = a[n - 1];
    for (int i = n - 3; i >= 0; i--) r[i] = gcd(r[i + 1], a[i + 1]);

    for (int i = 0; i < n; i++) {
        //cout << l[i] << " " << r[i] << " " << gcd(l[i], r[i]) << endl;
        if (gcd(l[i], r[i]) > mx) {
            mx = gcd(l[i], r[i]);
        }
    }

    cout << mx << endl;
}