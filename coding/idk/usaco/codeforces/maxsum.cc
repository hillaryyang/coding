//https://codeforces.com/contest/1832/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, k, x, sum = 0, ans = 0;
        cin >> n >> k;

        vector<ll> a, pa, pb;

        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}
        sort(a.begin(), a.end());
        for (ll c : a) sum += c;

        pa.push_back(0); pa.push_back(a[0] + a[1]);
        for (int i = 2; i < n; i += 2) pa.push_back(pa[i/2] + a[i] + a[i + 1]);

        pb.push_back(0); pb.push_back(a[n - 1]);
        for (int i = n - 2; i >= 0; i--) pb.push_back(pb[n - i - 1] + a[i]);

        //remove i minimums
        for (int i = 0; i <= k; i++) {
            ll temp = sum;

            temp -= pa[i]; temp -= pb[k - i];
            ans = max(ans, temp);
        }

        cout << ans << endl;
    }
}