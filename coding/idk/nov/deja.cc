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
        int n, q, o; ll p; vector<ll> a, pre(1e5); vector<int> temp, x;
        cin >> n >> q;

        for (int i = 0; i < n; i++) {cin >> p; a.pb(p);}
        for (int i = 0; i < q; i++) {cin >> o; temp.pb(o);}

        x.pb(temp[0]);
        for (int i = 1; i < q; i++) {
            if (temp[i] < x.back()) x.pb(temp[i]);
        }
        
        //for (int i : x) cout << i << " "; cout << endl;
        //prefix sums
        q = x.size();

        pre[q - 1] = pow(2, x[q - 1] - 1);
        for (int i = q - 2; i >= 0; i--) {
            //cout << pre[i + 1] << " " << pow(2, x[i] - 1) << endl;
            pre[i] = pre[i + 1] + pow(2, x[i] - 1);
        }

        //for (int i = 0; i <= q; i++) cout << pre[i] << " "; cout << endl;

        //loop thru and find greatest power of 2
        for (int i = 0; i < n; i++) {
            ll num = a[i], ct = 0;

            while (num) {
                if (((num & 1) | 0) == 0) ct++;
                else break; 
                num >>= 1;
            }

            //find the upper bound 
            auto it = upper_bound(x.rbegin(), x.rend(), ct);
            int loc = it - x.rbegin();

            //cout << a[i] << " " << ct << " " << loc << endl;

            a[i] += pre[q - loc];
        }

        for (ll i : a) cout << i << " "; cout << endl;
    }
}