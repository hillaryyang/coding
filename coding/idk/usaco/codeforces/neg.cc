#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, x, sum = 0, ct = 0; cin >> n;
        bool zero = false;

        vector<ll> a, temp;

        for (int i = 0; i < n; i++) {
            cin >> x; a.push_back(x); 
            if (x == 0) zero = true;
        }

        for (int i = 0; i < n; i++) if (a[i] < 0) ct++;

        for (int i = 0; i < n; i++) {
            if (a[i] < 0) temp.push_back(a[i] * -1);
            else temp.push_back(a[i]);

            sum += temp.back();
        }

        if (!zero) {
            if (ct % 2 == 0) {cout << sum << endl; continue;}
            else {
                ll mn = 1e9;
                for (int i = 0; i < n; i++) mn = min(mn, temp[i]);
                cout << sum - 2 * mn << endl; continue;
            }
        }

        else cout << sum << endl;

        a.clear(); temp.clear();
    }
}