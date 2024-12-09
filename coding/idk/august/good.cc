//https://codeforces.com/contest/1856/problem/B
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
        ll n, x, ct = 0, sum = 0; cin >> n;
        vector<ll> a;

        for (int i = 0; i < n; i++) {cin >> x; sum += x; a.pb(x); if (x == 1) ct++;}

        if (n == 1) cout << "NO" << endl;
        else if (ct > n/2) {
            //cout << sum << endl;
            if (n + ct <= sum) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
}