//https://codeforces.com/contest/1795/problem/C
#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, x; cin >> n;
        vector<ll> a, amt, pre;
        ll ct[n + 5], ans[n + 5];
        memset(ct, 0, sizeof(ct)); memset(ans, 0, sizeof(ans));

        a.push_back(0); amt.push_back(0);
        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}
        for (int i = 0; i < n; i++) {cin >> x; amt.push_back(x);}

        if (n == 1) {
            cout << min(a[1], amt[1]) << endl; continue;
        }

        //finding prefix
        pre.push_back(0);
        for (int i = 1; i <= n; i++) pre.push_back(pre[i - 1] + amt[i]);

        //looping over the cups
        for (int i = 1; i <= n; i++) {
            //binary search to find the point where pre[j] <= a[i] + pre[i - 1]
            ll l = i, r = n, y = 0;          
            while (l <= r) { 
                ll mid = (l + r)/2;
                if (pre[mid] <= a[i] + pre[i - 1]) {l = mid + 1; y = mid + 1;}
                else r = mid - 1;
            }

            if (y == 0) ans[i] += min(a[i], amt[i]);
            else if (y > n) {ct[i]++;}

            else {            
                ct[i]++; ct[y]--;
                ans[y] += min(max((ll)0, a[i] - (pre[y - 1] - pre[i - 1])), amt[y]);
            }
        }

        vector<int> pref;
        pref.push_back(ct[0]);
        for (int i = 1; i <= n; i++) pref.push_back(pref[i - 1] + ct[i]);
        for (int i = 1; i <= n; i++) ans[i] += pref[i] * amt[i];
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}