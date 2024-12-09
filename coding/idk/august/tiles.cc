//https://codeforces.com/contest/1851/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 2e5 + 10;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k, x, val, f; 
        cin >> n >> k;

        vector<vector<int> > c(n + 10);

        for (int i = 0; i < n; i++) {
            cin >> x; c[x].pb(i + 1);
            if (i == 0) f = x;
            if (i == n - 1) val = x; 
        }

        //for (auto i : c) if (!i.empty()) {for (int j : i) cout << j << " "; cout << endl;}        
        //cout << f << " " << val << endl;
        //cout << c[val][c[val].size() - k] << " " <<  c[f][k - 1] << endl;

        if (c[val].size() < k || c[f].size() < k) cout << "NO" << endl; 
        else if (f == val && c[f].size() >= k) cout << "YES" << endl;
        else if (c[val][c[val].size() - k] > c[f][k - 1]) cout << "YES" << endl;
        else cout << "NO" << endl;

        //cout << c[f][k - 1] << endl << c[val][c[val].size() - k] << endl;
    }
}