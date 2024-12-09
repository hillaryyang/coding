#include <iostream>
#include <algorithm>
using namespace std;

int n, loc[101], big;

int solve(int start, bool left) {
    int last = start, rad = 1;

    while (last > 0 && last < n-1) {
        int dir = 0;
        if (left) dir = -1; else dir = 1;

        int nex = last;
        while (nex + dir >= 0 && nex + dir < n && abs(loc[nex+dir] - loc[last]) <= rad) nex += dir;

        if (nex == last) break;
        //if the next explosion doesn't reach the next bale, then we break

        last = nex;
        rad++;
    }

    return last;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> loc[i];

    sort(loc, loc+n);

    for (int i = 0; i < n; i++) {
        int left = solve(i, true);
        int right = solve(i, false);

        big = max(big, right - left + 1);
    }

    cout << big << endl;
}