//https://codeforces.com/contest/329/problem/B
#include <iostream>
#include <tuple>
#include <cstring>
#include <queue>
#include <algorithm>
const int N = 1010;
using namespace std;

int r, c, d, e1, e2, s1, s2, ct;
char forest[N][N];
int visited[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int path(int x, int y) {
    queue<tuple<int, int, int> > q;
    q.push({x, y, 0});

    while (!q.empty()) {
        int a = get<0>(q.front()), b = get<1>(q.front()), d = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x1 = a + dx[i], y1 = b + dy[i];
            if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c && visited[x1][y1] == -1 && forest[x1][y1] != 'T') {
                q.push({x1, y1, d + 1});
                visited[x1][y1] = d + 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++) {
            forest[i][j] = s[j];
            if (s[j] == 'S') {s1 = i; s2 = j;}
            if (s[j] == 'E') {e1 = i; e2 = j;}
        }
    }

    memset(visited, -1, sizeof(visited));
    
    visited[e1][e2] = 0;
    path(e1, e2);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int k = forest[i][j] - '0';
            if (k > 0 && k <= 9) {
                int l = visited[i][j];
                if (l <= visited[s1][s2] && l >= 0) ct += k;
            }
        }
    }

    cout << ct << endl;
    
}