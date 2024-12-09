#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, x, y, a;
bool farm[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y) {
    return x>=0 && x<=n && y >=0 && y<=n;
}

bool c(int x, int y) {
    if (farm[x][y] == 0) return 0;
    int b = 0;

    for (int i = 0; i < 4; i++) {
        if (ok(x+dx[i], y+dy[i])) {
            if (farm[x+dx[i]][y+dy[i]]) b++;
        }
    }

    return b==3;
}

int main() {
    cin >> n; 

    for (int i = 0; i < n; i++) {
        cin >> x >> y; 

        for (int i = 0; i < 4; i++) {
            if (ok(x+dx[i], y+dy[i])) a-=c(x+dx[i], y+dy[i]);
        }

        farm[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            if (ok(x+dx[i], y+dy[i])) a+=c(x+dx[i], y+dy[i]);
        }
        cout << a << endl;
    }
}