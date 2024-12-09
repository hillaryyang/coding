//https://codeforces.com/contest/1862/problem/B
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
        ll n, x; cin >> n;
        vector<ll> a, b;

        for (int i = 0; i < n; i++) {cin >> x; b.pb(x);}
        
        a.pb(b[0]);

        for (int i = 1; i < n; i++) {
            if (a.back() != 1) a.pb(1); 
            a.pb(b[i]);
        }

        cout << a.size() << endl;
        for (int i : a) cout << i << " "; cout << endl;
    }
}