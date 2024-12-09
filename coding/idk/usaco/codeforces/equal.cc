//https://codeforces.com/contest/1799/problem/B
#include <iostream>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

vector<int> a;

int main() {
    ll t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<pair<ll, ll> > op;

        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        int temp = 30 * n;

        while (temp--) {
            ll mn = 1e9, idx;

            //if its the same we break
            bool ok = true;
            for (int i = 0; i < n; i++) if (a[i] != a[0]) {ok = false; break;}

            if (!ok) {
                //finds minimum and where it is
                for (int i = 0; i < n; i++) if (a[i] < mn) {mn = a[i]; idx = i + 1;}

                //cout << mn <<endl;

                for (int i = 0; i < n; i++) {
                    if (a[i] != mn) {
                        float r1 = a[i], r2 = mn;
                        a[i] = ceil(r1/r2); 
                        op.push_back(make_pair(i + 1, idx));
                    }
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) if (a[i] != a[0]) {ok = false; break;}

        if (ok) {
            cout << op.size() << endl;
            for (int i = 0; i < op.size(); i++) cout << op[i].first << " " << op[i].second << endl;
        }

        else cout << -1 << endl;

        a.clear(); 
    }
}