//https://codeforces.com/contest/1840/problem/B
#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, k; cin >> n >> k;

        ll temp = n, ct = 0;
        while (temp) {temp >>= 1; ct++;} ct--;
        
        if (k > ct) cout << n + 1 << endl;
        else {
            int x = 1;
            for (int i = 0; i < k; i++) x *= 2;
            cout << x << endl;
        }
    }
}