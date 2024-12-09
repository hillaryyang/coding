//http://www.usaco.org/index.php?page=viewproblem2&cpid=919
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb push_back
#define ll long long
const int N = 1010;
using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k, x1, y1, x2, y2, pre[N][N], a[N][N], ct = 0; 
    cin >> n >> k;

    memset(a, 0, sizeof(a)); memset(pre, 0, sizeof(pre));

    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        a[x1][y1]++; a[x1][y2]--;
        a[x2][y1]--; a[x2][y2]++;
    }

    /*for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cout << a[i][j] << " "; cout << endl;
    } cout << endl;*/

    for (int i = 1; i <= 1002; i++) {
        for (int j = 1; j <= 1002; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= 1002; i++) {
        for (int j = 1; j < 1002; j++) if (pre[i][j] == k) ct++;
    }

    cout << ct << endl;
}