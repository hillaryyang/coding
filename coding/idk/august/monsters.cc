//https://codeforces.com/problemset/problem/1849/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define f first 
#define s second 
#define mp make_pair
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, k, x; cin >> n >> k;
        vector<ll> z; vector<pair<ll, ll> > p;

        for (int i = 0; i < n; i++) {
            cin >> x; 
            x = x % k;
            if (x == 0) z.pb(i + 1);
            else p.pb(mp(x, i + 1));
        }

        sort(z.begin(), z.end());
        sort(p.begin(), p.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        for (int i : z) cout << i << " "; for (auto i : p) cout << i.s << " "; cout << endl;
    }
}