//http://www.usaco.org/index.php?page=viewproblem2&cpid=714
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#define mp make_pair
#define ll long long
#define pb push_back
#define s second
#define f first
using namespace std;

ll N, C, ct = 0, x; 
vector<pair<ll, ll> > n;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    cin >> C >> N;
    multiset<ll> chickens;

    for (int i = 0; i < C; i++) {cin >> x; chickens.insert(x);}
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b; n.pb(mp(b, a));
    }

    sort(n.begin(), n.end());
    for (auto i : n) {
        auto it = chickens.lower_bound(i.s);
        if (it != chickens.end() && *it <= i.f) {ct++; chickens.erase(it);}
    }

    cout << ct << endl;
}