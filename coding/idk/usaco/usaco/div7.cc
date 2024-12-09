//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll n, x, mx, d[500000];
vector<ll> p, m;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> d[i];

    //prefix sums
    p.push_back(d[0]);
    for (ll i = 1; i < n; i++) p.push_back(d[i] + p[i - 1]);

    //p mod 7
    for (ll a : p) m.push_back(a % 7);

    for (ll i = 0; i < n/2; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (m[i] == m[j]) {
                mx = max(mx, j - i);
            }
        }
    }

    cout << mx << endl;
}
