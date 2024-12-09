/*
ID: hillary3
TASK: wormhole
LANG: C++                 
*/

#include <iostream>
using namespace std;

int n, x[13], y[13], p[13], r[13]; 

bool cycle(void) {
    for (int s = 1; s <= n; s++) {
        int pos = s;
        for (int ct = 0; ct < n; ct++) pos = r[p[pos]];
        if (pos != 0) return true;
    }
    return false;
}

int solve(void) {
    int i, ct = 0;
    for (i = 1; i <= n; i++) {
        if (p[i] == 0) break;
    }

    if (i > n) {
        if (cycle()) return 1;
        return 0;
    }

    for (int j = i + 1; j <= n; j++) {
        if (p[j] == 0) {
            p[i] = j; p[j] = i;
            ct += solve();
            p[i] = 0; p[j] = 0;
        }
    }

    return ct;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[j] > x[i] && y[i] == y[j]) {
                if (r[i] == 0 || x[j]-x[i] < x[r[i]] - x[i]) r[i] = j;
            }
        }
    }

    cout << solve() << endl;
}