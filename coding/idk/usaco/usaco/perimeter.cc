//http://www.usaco.org/index.php?page=viewproblem2&cpid=895
#include <iostream>
#include <vector>
#include <algorithm>
#define pi pair<int, int>
using namespace std;

int n, ice[1010][1010], area, peri;
bool visited[1010][1010];
vector<pair<int, int> > vals;

void floodfill (int x, int y) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    if (x < 0 || x > n - 1 || y < 0 || y > n - 1 
    || ice[x][y] != '#' || visited[x][y]) return;

    visited[x][y] = true;
    area++;
    
    //check the squares around it to find the perimeter that it adds
    int h = 0;
    for (int i = 0; i < 4; i++) if (ice[x + dx[i]][y + dy[i]] == '#') h++;

    peri += (4 - h);

    for (int i = 0; i < 4; i++) floodfill(x + dx[i], y + dy[i]);
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) ice[i][j] = s[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ice[i][j] == '#' && !visited[i][j]) {
                area = 0; peri = 0;
                floodfill(i, j); 

                vals.push_back(make_pair(area, peri));
            }
        }
    }

    sort(vals.begin(), vals.end(), [](pi a, pi b) {
        if (a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    });

    cout << vals[0].first << " " << vals[0].second << endl;
}