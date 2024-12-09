//https://codeforces.com/contest/1843/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, x, sum = 0, ct = 0, loc; cin >> n;
        vector<ll> a;
        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x); sum += abs(x);}

        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                ct++;
                for (int j = i; j < n; j++) if (a[j] > 0 || j == n - 1) {loc = j; break;}
                i = loc;
            }
        }

        cout << sum << " " << ct << endl;
    }
}