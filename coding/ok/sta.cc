#include <iostream>
#include <cstring>
using namespace std;

int n, k;
char canvas[21][21], stamp[21][21], temp[21][21], ans[21][21];

void rotate() {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) temp[i][j] = stamp[j][k-i-1];
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) stamp[i][j] = temp[i][j];
    }
}

void work(int a, int b) {
    //a, b are the upper left coordinates of where we want to stamp

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (stamp[i][j] == '*' && canvas[a + i][b + j] == '.') return;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (stamp[i][j] == '*') {ans[a + i][b + j] = '*';}
        }
    }
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> canvas[i];

        cin >> k;
        for (int i = 0; i < k; i++) cin >> stamp[i];

        memset (ans, '.', sizeof(ans));

        for (int rot = 0; rot < 4; rot++) {
            rotate();
            for (int i = 0; i < n - k + 1; i++) {
                for (int j = 0; j < n - k + 1; j++) work (i, j);
            }
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] != canvas[i][j]) flag = false;
            }
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}