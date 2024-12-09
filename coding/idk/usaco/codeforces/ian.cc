//https://codeforces.com/contest/1816/problem/C
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, x; cin >> n;
        vector<ll> a;

        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        for (int i = 0; i < n - 2; i++) {
            if (a[i] > a[i + 1]) {
                ll c = a[i] - a[i + 1];
                a[i + 1] = a[i]; a[i + 2] += c;
            }
        }

        for (int i = n - 1; i > 1; i--) {
            if (a[i] < a[i - 1]) {
                ll d = a[i - 1] - a[i];
                a[i - 1] = a[i]; a[i - 2] -= d;
            }
        }

        /*for (auto c : a) cout << c << " ";
        cout << endl;*/

        bool ok = true;

        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {ok = false; break;}
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;

        a.clear();
    }
}