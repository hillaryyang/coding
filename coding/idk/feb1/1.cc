#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;

int main() {
    ll t, n, q, c, x, y;
    cin >> t;

    while (t--) {
        vector<ll> a;
        vector<pair<ll, ll> > p;
        cin >> n >> q >> c;

        for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}
        for (int i = 0; i < q; i++) {
            cin >> x >> y; 
            if (a[x] != 0 && a[y] == 0) {a[y] = a[x] + 1; continue;}
            p.pb(mp(x, y));
        }

        sort(p.begin(), p.end());

        //!!! no cow has cowpetency greater than c
        //!!! check if cur greater than mx if in p

        //looping through the cowpetency scores
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            //keep track of the mx up to the looping point
            mx = max(mx, a[i]);


        }
    }
}