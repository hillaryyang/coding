//http://www.usaco.org/index.php?page=viewproblem2&cpid=939
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define f first 
#define mp make_pair
using namespace std;

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    char farm[11][11]; string s;
    int bx, by, rx, ry, lx, ly;

    for (int i = 0; i < 10; i++) {
        cin >> s;
        for (int j = 0; j < 10; j++) {
            farm[i][j] = s[j];
            if (s[j] == 'B') {bx = i; by = j;}
            else if (s[j] == 'R') {rx = i; ry = j;}
            else if (s[j] == 'L') {lx = i; ly = j;}
        }
    }

    int ans = abs(bx - lx) + abs(by - ly) - 1;

    if (bx == rx && rx == lx && 
    ((ly < ry) && (ry < by) || (by < ry) && (ry < ly))) cout << ans + 2 << endl;
    else if (by == ry && ry == ly && 
    ((lx < rx) && (rx < bx) || (bx < rx) && (rx < lx))) cout << ans + 2 << endl;
    else cout << ans << endl;
}