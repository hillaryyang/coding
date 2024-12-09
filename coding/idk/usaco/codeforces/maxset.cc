//https://codeforces.com/contest/1796/problem/C
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
    
int main() {
    ll t, l, r; cin >> t;
    
    while (t--) {
        cin >> l >> r;
    
        if (l == r) {cout << 1 << " " << 1 << endl; continue;}
        else if (l == r - 1) {
            if (l == 1) cout << 2 << " " << 1 << endl;
            else cout << 1 << " " << 2 << endl;
            continue;
        }
    
        ll ans1 = 0, num = 0, ans2 = 0, temp = l;

        //find the maximum possible size of a beautiful set
        while (temp <= r) {ans1++; temp *= 2;}
        cout << ans1 << " ";
    
        ll a = ((ll)(r/pow(2, ans1-1)) - l + 1) % 998244353;
        ll x = r/(((ll) (pow(2, ans1-2) * 3) % 998244353));
        ll y = max((ll) 0, ((x - l + 1) * (ans1 - 1))) % 998244353;

        cout << a + y << endl;
    }
}