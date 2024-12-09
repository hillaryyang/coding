//http://www.usaco.org/index.php?page=viewproblem2&cpid=596
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 4003;
using namespace std;

bool grid[N][N], vis[N][N];
int n, x = 2001, y = 2001, minx = 2001, maxx = 2001, miny = 2001, maxy = 2001; 
string s;

void ff (int i, int j) {
    if (i < minx || i > maxx || j < miny || j > maxy || vis[i][j] || grid[i][j]) return;
    vis[i][j] = true;

    ff(i + 1, j); ff(i - 1, j); ff(i, j + 1); ff(i, j - 1);
}

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    
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
    int ans = 0;

    for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            if (!vis[i][j] && !grid[i][j]) {ans++; ff(i, j);}
        } 
    }   

    cout << ans - 1 << endl;
}