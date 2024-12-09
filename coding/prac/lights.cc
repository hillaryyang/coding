//http://www.usaco.org/index.php?page=viewproblem2&cpid=570
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
#define pb push_back
#define f first
#define s second
#define pii pair<int, int>
#define mp make_pair
const int N = 105;
using namespace std;

bool grid[N][N], vis[N][N], vi[N][N];
int n, m, x, y, a, b, ct; // xmn = N, ymn = N, xmx = -1, ymx = -1;
multimap<pair<int, int>, pair<int, int> > sw;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void reach (int i, int j) {
    //cout << i << " " << j << endl;
    if (vi[i][j] || !grid[i][j] || i < 1 || i > n || j < 1 || j > n) return;
    vi[i][j] = true;
    for (int k = 0; k < 4; k++) reach(i + dx[k], j + dy[k]);
}

void solve(int i, int j) {
    if (vis[i][j] || i < 1 || i > n || j < 1 || j > n) return;

    vis[i][j] = true;

    auto it1 = sw.lower_bound(mp(i, j)), it2 = sw.upper_bound(mp(i, j));

    while (it1 != it2) {
        //cout << it1 -> f.f << " " << it1 -> f.s << " " << it1 -> s.f << " " << it1 -> s.s  << endl;
        grid[it1 -> s.f][it1 -> s.s] = true; 
        reach(it1 -> s.f, it1 -> s.s);
        if (vi[i][j]) {solve(it1 -> s.f, it1 -> s.s); memset(vi, 0, sizeof(vi));}
        it1++;
    }

    for (int k = 0; k < 4; k++) if (grid[i + dx[k]][j + dy[k]]) solve(i + dx[k], j + dy[k]);
}

int main() {
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        sw.insert(pair<pii, pii>(mp(x, y), mp(a, b)));
    }

    //for (auto i : sw) cout << i.f.f << " " << i.f.s << " " << i.s.f << " " << i.s.s << endl;

    grid[1][1] = true; solve(1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {if (grid[i][j]) ct++;}
    }

    cout << ct << endl;
}