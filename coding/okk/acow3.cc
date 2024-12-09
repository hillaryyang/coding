//http://www.usaco.org/index.php?page=viewproblem2&cpid=1133
#include <iostream>
#include <vector>
#include <set>
#define mp make_pair
#define pb push_back
#define f first
#define s second
using namespace std;

const int N = 1010;

int n, m, ids[N][N], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool l, r, d, u;
set<pair<int, int> > bad;
char a[N][N];

void adj(int x, int y) {
    l = 0, r = 0, d = 0, u = 0;
    /*int ct = 0;
    for (int i = 0; i < 4; i++) {
        if (a[x + dx[i]][y + dy[i]] == 'C') ct++;
    }*/

    if (a[x - 1][y] == 'C') u = true;
    if (a[x + 1][y] == 'C') d = true;
    if (a[x][y + 1] == 'C') r = true;
    if (a[x][y - 1] == 'C') l = true;

    //return ct;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        for (int j = 0; j < m; j++) a[i + 1][j + 1] = x[j];
    }

    int ct = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'C') { ids[i][j] = ct; ct++; }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ids[i][j];
        } cout << endl;
    }*/


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'G') { 
                adj(i, j);
                //2 cows
                if (u + r + d + l == 2) {
                    if (u && r) bad.insert(mp(ids[i - 1][j], ids[i][j + 1]));
                    else if (d && r) bad.insert(mp(ids[i][j + 1], ids[i + 1][j]));
                    else if (d && l) bad.insert(mp(ids[i][j - 1], ids[i + 1][j]));
                    else if (u && l) bad.insert(mp(ids[i - 1][j], ids[i][j - 1]));
                    else if (u && d) bad.insert(mp(ids[i - 1][j], ids[i + 1][j]));
                    else if (r && l) bad.insert(mp(ids[i][j + 1], ids[i][j - 1]));
                }

                else if (u + r + d + l == 3) {
                    if (l && r) bad.insert(mp(ids[i][j + 1], ids[i][j - 1]));
                    else if (u && d) bad.insert(mp(ids[i - 1][j], ids[i + 1][j]));
                }

                else if (u + r + d + l == 4) {
                    bad.insert(mp(ids[i - 1][j], ids[i + 1][j]));
                }
            }
        }
    }

    cout << bad.size() << endl;
}