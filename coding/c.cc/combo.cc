/*
ID: hillary3
TASK: combo
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, fj[3], m[3], ct;

bool works1(int a, int b, int c) {
    if ((abs(fj[0] - a) <= 2 || abs(fj[0] - a) >= n - 2) 
    && (abs(fj[1] - b) <= 2 || abs(fj[1] - b) >= n - 2)
    && (abs(fj[2] - c) <= 2 || abs(fj[2] - c) >= n - 2)) return true;
    return false;
}

bool works2(int a, int b, int c) {
    if ((abs(m[0] - a) <= 2 || abs(m[0] - a) >= n - 2) 
    && (abs(m[1] - b) <= 2 || abs(m[1] - b) >= n - 2)
    && (abs(m[2] - c) <= 2 || abs(m[2] - c) >= n - 2)) return true;
    return false;
}

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < 3; i++) cin >> fj[i];
    for (int i = 0; i < 3; i++) cin >> m[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (works1(i, j, k) || works2(i, j, k)) {
                    //cout << i << " " << j << " " << k << endl;
                    ct++;
                }
            }
        }
    }

    cout << ct << endl;
}