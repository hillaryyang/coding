//http://www.usaco.org/index.php?page=viewproblem2&cpid=489
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set> 
const int N = 1e5 + 10;
#define ll long long
using namespace std;

ll n, x, y, ct = 1, loc;
vector<ll> s;

int main() {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y; s.push_back(y);
    }

    s.resize(n);

    ll mn = s[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] <= mn) ct++;
        mn = min(mn, s[i]);
    }

    cout << ct << endl;
}