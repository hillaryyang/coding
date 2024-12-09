//https://codeforces.com/problemset/problem/1859/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t, n, m, x; cin >> t;

    while (t--) {
        cin >> n;

        vector<vector<ll> > a(n);

        for (int i = 0; i < n; i++) {
            cin >> m;
            while (m--) {cin >> x; a[i].push_back(x);}
        }

        for (int i = 0; i < n; i++) sort(a[i].begin(), a[i].end());

        /*for (int i = 0; i < n; i++) {
            for (int j : a[i]) cout << j << " "; cout << endl;
        }*/
        
        ll mn1 = 1e9 + 10, mn2 = 1e9 + 10, sum = 0;
        for (int i = 0; i < n; i++) {mn1 = min(mn1, a[i][0]); mn2 = min(mn2, a[i][1]);}
        sum += mn1;

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (a[i][1] == mn2 && !flag) flag = true;
            else sum += a[i][1];
        }

        cout << sum << endl; 
    }
}