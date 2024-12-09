/*
ID: hillary3
TASK: numtri
LANG: C++                 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int r, tri[1000][1000], res[1000];

int main() {
    //freopen ("numtri.in", "r", stdin);
    //freopen ("numtri.out", "w", stdout);

    cin >> r;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) cin >> tri[i][j];
    }

    for (int i = 0; i < r; i++) res[i] = tri[r-1][i];
    
    for (int i = r-1; i > 0; i--) {
        for (int j = 0; j <= i; j++) {
            res[j] = tri[i-1][j] + max(res[j], res[j+1]);
        }
    }

    cout << res[0] << endl;
}