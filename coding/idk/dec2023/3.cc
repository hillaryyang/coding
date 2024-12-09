#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
#define pb push_back
#define f first
#define s second
#define pii pair<ll, ll>
#define mp make_pair
const int N = 105;
using namespace std;

int main() {
    int t; cin >> t; 

    while (t--) {
        ll n, t; vector<ll> h, g;
        vector<pair<int, pii> > b;

        cin >> n;
        h.resize(n); g.resize(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        for (int i = 0; i < n; i++) cin >> g[i];

        for (int i = 0; i < n; i++) {
            cin >> t; b.pb(mp(t, mp(h[i], g[i])));
        }

        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {h[i] = b[i].s.f; g[i] = b[i].s.s;}

        //for (int i = 0; i < n; i++) cout << h[i] << " "; cout << endl; 
        //for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

        ll mx = 1e9, mn = 0; bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            //comparing i and i + 1
            ll a = h[i], b = h[i + 1], c = g[i], d = g[i + 1];
            //cout << a << " " << b << " " << c << " " << d << endl;

            if (a > b) {
                if (c < d) {
                    //cout << floor((double) (a - b)/(d - c)) << endl;
                    //of the format d < something
                    if ((a - b) % (d - c) == 0) mx = min(mx, (a - b)/(d - c) - 1);
                    else mx = min(mx, (ll) floor((double) (a - b)/(d - c)));
                } 
            }

            else if (a == b && c <= d) {ok = false; break;}

            else if (a < b) {
                if (c > d) {
                    //format will be (c - d) days > b - a
                    if ((b - a) % (c - d) == 0) mn = max(mn, ((b - a)/(c - d)) + 1);
                    else mn = max(mn, (ll) ceil((double) (b - a)/(c - d)));
                }
                else {ok = false; break;}
            }
        }

        if (!ok || mx < mn) {cout << -1 << endl; continue;}

        else cout << mn << endl;
    }
}