//http://www.usaco.org/index.php?page=viewproblem2&cpid=380
#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

ll m, n, a, b, elev[510][510];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[510][510];
vector<pair<ll, ll> > wp;

void floodfill(ll x, ll y, ll d) {
    if (x < 0 || x > m || y < 0 || y > n || visited[x][y]) return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        ll nx = x + dx[i], ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n
        && !visited[nx][ny] && abs(elev[nx][ny] - elev[x][y]) <= d) floodfill(nx, ny, d);
    }
}

bool check() {
    for (int i = 0; i < wp.size(); i++) {
        if (!visited[wp[i].first][wp[i].second]) return false;
    }

    return true;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    cin >> m >> n; 

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> elev[i][j];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a; if (a == 1) wp.push_back(make_pair(i, j));
        } 
    }

    a = wp[0].first, b = wp[0].second;

    //binary search over possible difficulty levels
    ll l = 0, r = 1e9, ans;
    while (l <= r) {
        ll mid = (l + r)/2;
        floodfill(a, b, mid);
        if (check()) {r = mid - 1; ans = mid;}
        else l = mid + 1; 
        
        memset(visited, false, sizeof(visited));
    }

    cout << ans << endl;
}