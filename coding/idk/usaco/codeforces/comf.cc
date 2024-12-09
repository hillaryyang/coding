#include <iostream>
#include <vector>
#define ll long long
const int N = 1e3;
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, grid[N][N], ct = 0; cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        for (int j = 0; j < 4; j++) {
            if (x + dx[j] >= 0 && x + dx[j] < N
            && y + dy[j] >= 0 && y + dy[j] < N) {
                grid[x + dx[j]][y + dy[j]]++;
                if (grid[x + dx[j]][y + dy[j]] == 3) ct++;
                else if (grid[x + dx[j]][y + dy[j]] == 4) ct--;
            }
        }

        cout << ct << endl;
    }
}