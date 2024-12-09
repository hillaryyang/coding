//https://codeforces.com/problemset/problem/1850/E
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

ll n, c, x;
vector<ll> a;

ll check(ll mid) {
    ll sum = 0;

    for (int i : a) {
        sum += (i + 2 * mid) * (i + 2 * mid);
        if (sum > c) return 1;
    }

    if (sum < c) return -1;
    return 0;
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> n >> c;
        a.clear();

        for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

        ll l = 0, r = 1e9, mid;
        while (l <= r) {
            mid = (l + r)/2;
            if (check(mid) == 1) r = mid - 1;
            else if (check(mid) == -1) l = mid + 1;
            else break;
        }

        cout << mid << endl;
    }
}