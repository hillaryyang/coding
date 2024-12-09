//https://codeforces.com/contest/1816
#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        
        int a[2][200000];

        a[0][0] = 2 * n; a[1][n - 1] = 2 * n - 1;

        for (int i = 1; i <= n - 1; i += 2) a[0][i] = i + 1;
        for (int i = 0; i <= n - 2; i += 2) a[1][i] = i + 1;

        /*for (int i = 1; i <= n - 1; i += 2) a[0][i] = i;
        for (int i = 0; i <= n - 2; i += 2) a[1][i] = i + 2;*/

        for (int i = 2; i <= n - 2; i += 2) a[0][i] = n + i;
        for (int i = 1; i <= n - 3; i += 2) a[1][i] = n + i;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) cout << a[i][j] << " ";
            cout << endl;
        }
    }
}