//https://codeforces.com/problemset/problem/1594/E1
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
const int N = 1010;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, q, o; ll p, min = 2e9; vector<ll> a; vector<int> x;
        cin >> n >> q;

        for (int i = 0; i < n; i++) {cin >> p; a.pb(p);}
        for (int i = 0; i < q; i++) {cin >> o; x.pb(o);}

        for (int i = 0; i < q; i++) {
            if (x[i] < min) {
                min = x[i];

                for (int j = 0; j < n; j++) {
                    if (a[j] % (ll)(pow(2, x[i])) == 0) a[j] += pow(2, x[i] - 1);
                }
            }
        }

        for (ll i : a) cout << i << " "; cout << endl;
    }
}