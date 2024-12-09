//https://codeforces.com/contest/1840/problem/C
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, k, q, x, ct = 0, sum = 0;
        vector<ll> a;
        cin >> n >> k >> q;

        for (int i = 0; i < n; i++) {
            cin >> x; 
            if (x <= q) ct++;
            else {a.push_back(ct); ct = 0;}
        } if (x <= q) a.push_back(ct);

        //for (int i : a) cout << i << " "; cout << endl;
        for (int i : a) {
            if (i >= k) {
                //total - top
                sum += ((i - k + 1)*(i-k+2)/2);
            }
        }

        cout << sum << endl;
    }
}