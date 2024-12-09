//https://codeforces.com/contest/1857/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t, n, x; cin >> t;

    while (t--) {
        cin >> n;

        vector<int> a, b, ans;
        vector<pair<ll, ll> > dif;
        
        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}
        for (int i = 0; i < n; i++) {cin >> x; b.push_back(x);}

        for (int i = 0; i < n; i++) dif.push_back(make_pair(a[i] - b[i], i + 1));

        sort(dif.begin(), dif.end());

        //for (auto i : dif) cout << i.first << " " << i.second << endl;

        int ct = 0, loc = n - 1;
        while (loc >= 0 && dif[loc].first == dif[n - 1].first) {
            ct++; ans.push_back(dif[loc].second);
            loc--;
        }

        cout << ct << endl; sort(ans.begin(), ans.end());
        for (int i : ans) cout << i << " "; cout << endl;
    }
}