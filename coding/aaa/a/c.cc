#include <iostream>
using namespace std;

int n, x, y, ans, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool farm[1000][1000];

bool ok(int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= n;
}

bool c(int x, int y) {
    //determines if the cow at (x, y) is comfortable
    if (farm[x][y] == 0) return 0;
    int a = 0;
    for (int i = 0; i < 4; i++) {
        if (ok(x+dx[i], y+dy[i])) {
            if (farm[x+dx[i]][y+dy[i]]) a++;
        }
    }

    return a == 3;
}   

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        for (int d = 0; d < 4; d++) {
            if (ok(x+dx[d], y+dy[d])) ans-=c(x+dx[d], y+dy[d]);
        }

        farm[x][y] = 1;

        for (int d = 0; d < 4; d++) {
            if (ok(x+dx[d], y+dy[d])) ans+=c(x+dx[d], y+dy[d]);
        }

        cout << ans << endl;
    }
}