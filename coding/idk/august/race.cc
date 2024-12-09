//http://www.usaco.org/index.php?page=viewproblem2&cpid=989
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 5e6 + 10;
using namespace std;

ll k, n, x, s, t, l;


ll sum(ll a, ll b) {
    if (a > b) return 0;
    return (b*(b+1) - a*(a-1))/2;
}

bool ok(ll s, ll dist) {
    if (s <= x) return true;
    return (sum(x, s - 1) <= dist);
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        s = 0, t = 0, l = k;
        cin >> x;

        while (l > 0) {
            //check if we can increase the speed
            if (ok(s + 1, l - s - 1)) s++;
            else if (!ok(s, l - s)) s--;
            t++; l -= s;

            //cout << t << " " << s << " " << l << endl;
        }

        cout << t << endl;
    }
}