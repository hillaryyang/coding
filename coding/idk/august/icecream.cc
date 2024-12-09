//https://codeforces.com/contest/1862/problem/C
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

ll check(ll mid) {
    return mid*(mid-1)/2;
}

int main() {
    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        
        ll x = sqrt(2 * n);

        bool ok = false; ll val;
        for (int i = x - 1; i <= x + 3; i++) {
            if (check(i) == n) {ok = true; val = i; break;}
            
            if (check(i) > n && check(i - 1) < n) {val = i - 1; break;}
        }

        if (ok) cout << val << endl;
        else cout << val + n - (check(val)) << endl;
    }
}