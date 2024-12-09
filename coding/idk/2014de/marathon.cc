//http://www.usaco.org/index.php?page=viewproblem2&cpid=487
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set> 
const int N = 1e5 + 10;
#define ll long long
using namespace std;

ll n, a, b, tot, mn = 1e10;
vector<ll> x, y, rem;

int main() {
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        x.push_back(a); y.push_back(b);
        if (i != 0) tot += (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]));
    }

    //cout << tot << endl;

    rem.push_back(0);
    for (int i = 1; i < n - 1; i++) {
        ll f = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) + abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
        mn = min(mn, tot - f + abs(x[i - 1] - x[i + 1]) + abs(y[i - 1] - y[i + 1]));
    }

    cout << mn << endl;
}