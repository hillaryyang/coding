//http://www.usaco.org/index.php?page=viewproblem2&cpid=738
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second
const int N = 501;
using namespace std;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    ll n, X, Y; cin >> n;
    vector<pair<ll, ll> > a;

    for (int i = 0; i < n; i++) {
        cin >> X >> Y; a.pb(mp(Y, X));
    }

    sort(a.begin(), a.end());

    ll i = 0, j = n - 1, mx = 0;
    while (i <= j) {
        ll mn = min(a[i].s, a[j].s);
        if(i == j) mn /= 2;
        a[i].s -= mn; a[j].s -= mn;

        mx = max(mx, a[i].f + a[j].f);

        if (a[i].s == 0) i++;
        if (a[j].s == 0) j--;
    }

    cout << mx << endl;
}