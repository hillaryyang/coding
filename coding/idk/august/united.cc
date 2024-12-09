//https://codeforces.com/problemset/problem/1859/A
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t, n, x; cin >> t;

    while (t--) {
        vector<ll> a, b;

        cin >> n;
        for (int i = 0; i < n; i++) { cin >> x; a.push_back(x); }
        sort(a.begin(), a.end());

        ll mx = a.back();
        while (a.back() == mx) {
            b.push_back(a.back()); a.pop_back(); 
        }

        if (a.size() == 0 || b.size() == 0) cout << -1 << endl;

        else {
            cout << a.size() << " " << b.size() << endl;
            for (int i : a) cout << i << " "; cout << endl;
            for (int i : b) cout << i << " "; cout << endl;
        }
    }
}