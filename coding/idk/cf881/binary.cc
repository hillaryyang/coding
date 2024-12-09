//https://codeforces.com/contest/1843/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, ans; cin >> n; 
        ans = n;

        while (n /= 2) ans += n;

        cout << ans << endl;
    }
}