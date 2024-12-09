//https://codeforces.com/contest/1201/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll n, k, ans;
vector<ll> a;

bool check(ll x) {
    //n is attainable with our operations
    ll tot = 0;
    for (int i = (n + 1)/2 - 1; i < n; i++) {
        tot += max((ll)0, x - a[i]);
    }

    if (tot <= k) return true;
    return false;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x; a.push_back(x);
    }

    sort(a.begin(), a.end());

    ll l = a[(n + 1)/2 - 1], r = l + k;

    while (l <= r) {
        ll mid = l + (r - l)/2;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        }

        else r = mid - 1;
    }

    cout << ans << endl;
}