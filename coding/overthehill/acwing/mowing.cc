#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int path[2010][2010];
vector <int> grow;

int main() {

    freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

    int t, x = 1000, y = 1000, ctime = 0, time;
    int dif = 0;
    char dir; 
    cin >> t;

    char n = 'N', s = 'S', e = 'E', w = 'W';

    while (t--) {
        cin >> dir >> time;
        path[1000][1000] = 0;

        if (dir == n) { //north
            for (int i = 1; i <= time; i++) {
                ctime++;
                if (path[x][y] != 0) {
                    dif = ctime - path[x][y];
                    grow.push_back(dif);
                }
                path[x][y++] = ctime;
            }
        }

        if (dir == s) { //south
            for (int i = 1; i <= time; i++) {
                ctime++;
                if (path[x][y] != 0) {
                    dif = ctime - path[x][y];
                    grow.push_back(dif);
                }
                path[x][y--] = ctime;
            }
        }

        if (dir == e) { //east
            for (int i = 1; i <= time; i++) {
                ctime++;
                if (path[x][y] != 0) {
                    dif = ctime - path[x][y];
                    grow.push_back(dif);
                }
                path[x++][y] = ctime;
            }
        }

        if (dir == w) { //west
            for (int i = 1; i <= time; i++) {
                ctime++;
                if (path[x][y] != 0) {
                    dif = ctime - path[x][y];
                    grow.push_back(dif);
                }
                path[x--][y] = ctime;
            }
        }
    }


    if (grow.empty()) cout << -1 << endl;
    else {
        sort (grow.begin(), grow.end());
        cout << grow.front() << endl;
    }
}