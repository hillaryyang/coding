//http://www.usaco.org/index.php?page=viewproblem2&cpid=596
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 4006;
using namespace std;

bool grid[N][N], visited[N][N];
int n, x = 2001, y = 2001, minx = 2001, maxx = 2001, miny = 2001, maxy = 2001, ans;
string s;

void floodfill(int r, int c) {
    //cout << r << " " << c << " " << endl;
    if (r < minx || r > maxx || c < miny || c > maxy || visited[r][c] || grid[r][c] == 1) return;

    visited[r][c] = true;

    floodfill(r, c + 1);
	floodfill(r, c - 1);
	floodfill(r - 1, c);
	floodfill(r + 1, c);
}

int main() {
    //freopen("gates.out", "w", stdout);
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        char dir = s[i];
        grid[x][y] = 1;

        if (dir == 'N') {grid[x - 1][y] = 1; x -= 2;}
        else if (dir == 'S') {grid[x + 1][y] = 1; x += 2;}
        else if (dir == 'E') {grid[x][y + 1] = 1; y += 2;}
        else {grid[x][y - 1] = 1; y -= 2;}

        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);   
    }
    minx--; miny--; maxx++; maxy++;

    for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            //cout << i << " " << j << endl;
            if (!visited[i][j] && grid[i][j] != 1) {ans++; floodfill(i, j);}
        }
    }

   cout << ans - 1 << endl;
   
}