//https://codeforces.com/contest/1365/problem/D
#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char ma[51][51];
bool visited[51][51];
int t, n, m;

void floodfill(int x, int y) {
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || ma[x][y] == '#' || visited[x][y]) return;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) floodfill(x + dx[i], y + dy[i]);
}

bool border (int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (ma[x][y] == 'G' && ma[x + dx[i]][y + dy[i]] == 'B') return false;
    }

    return true;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> m;
        bool flag = true;

        memset(visited, false, sizeof(visited));
        memset(ma, '\0', sizeof(ma));

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                ma[i][j] = s[j];
                if (s[j] == 'G') flag = false;
            }
        }  

        //check if there's bordering GB
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (!border(i, j)) {ok = false; break;}
        }

        if (!ok) {cout << "No" << endl; continue;}

        //block in the bad guys
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ma[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        if (ma[i + dx[k]][j + dy[k]] == '.') ma[i + dx[k]][j + dy[k]] = '#';
                    }
                }
            }
        }

        if (ma[n - 1][m - 1] != '.' && flag) {cout << "Yes" << endl; continue;}

        //floodfill from end
        floodfill(n - 1, m - 1);

        ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ma[i][j] == 'G' && !visited[i][j]) {ok = false; break;}
            }
        }

        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}