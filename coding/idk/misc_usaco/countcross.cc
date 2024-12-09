//http://www.usaco.org/index.php?page=viewproblem2&cpid=716
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define mp make_pair
#define ll long long
#define pb push_back
#define s second
#define f first
const int N = 300;
using namespace std;

char grid[N][N];
bool visited[N][N];
int n, k, R, r, c, r1, c1, no, ct, ans;
vector<pair<int, int> > pos;

void floodfill(int r, int c) {
    if ((r < 1 || r > 2 * n - 1|| c < 1 || c > 2 * n - 1) || grid[r][c] == '.' || visited[r][c]) return;

    visited[r][c] = true;

    if (grid[r][c] == 'C') no++;

    floodfill(r, c + 1); floodfill(r + 1, c); floodfill(r - 1, c); floodfill(r, c - 1);
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    cin >> n >> k >> R; 

    while (R--) {
        cin >> r >> c >> r1 >> c1;

        //if the road goes vertical
        if (r == r1) {
            if (c > c1) swap(c, c1);
            //cout << r << " " << c << " " << r1 << " " << c1 << endl;
            for (int i = 2 * r - 2; i <= 2 * r; i++) {
                grid[i][2 * c] = '.';
            }
        }

        else {
            if (r > r1) swap(r, r1);
            for (int i = 2 * c - 2; i <= 2 * c; i++) grid[2 * r][i] = '.';
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        pos.pb(mp(2 * r - 1, 2 * c - 1));
        grid[2 * r - 1][2 * c - 1] = 'C';
    }

    sort(pos.begin(), pos.end());

    for (auto i : pos) {
        memset(visited, 0, sizeof(visited)); no = 0; 
        floodfill(i.f, i.s);

        /*for (int i = 1; i <=2 * n - 1; i++) {
            for (int j = 1; j <= 2 * n - 1; j++) cout << visited[i][j];
            cout << endl;
        } */

        //cout << i.f << " " << i.s << " " << k - no << endl;
        ct += k - no;
    }
    //cout << ct << endl;

    cout << ct/2 << endl;

    /*for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            if (grid[i][j] == '.' || grid[i][j] == 'C') cout << grid[i][j];
            else cout << "E";
        }
        cout << endl;
    }*/
}
