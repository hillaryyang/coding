//https://codeforces.com/problemset/problem/1853/B
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
        ll k, ct = 0, n; cin >> n >> k;
        
        for (int i = n/2; i <= n; i++) {
            ll cur = i, last = n, z = ceil(log10(k)) + 20;
            bool ok = true;

            for (int j = 1; j <= min(z, k - 2); j++) {

                ll temp = cur; cur = last - temp; last = temp;

                if (cur < 0 || last < 0 || cur > last) {ok = false; break;}
            }

            if (ok) {
                //cout << i << endl;
                ct++;
            }
        }

        cout << ct << endl;
    }
}