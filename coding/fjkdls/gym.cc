#include <iostream>
using namespace std;

int n, k, ct;
int rk[20][20];

bool works (int a, int b) {
    for (int i = 0; i < k; i++) {
        int aloc = 0, bloc = 0;

        for (int j = 0; j < n; j++) {
            if (rk[i][j] == a) aloc = j;
            else if (rk[i][j] == b) bloc = j;
        }

        //cout << aloc << " " << bloc << endl;

        if (aloc > bloc) return false;
    }

    return true;
}

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) cin >> rk[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (works(i, j) || works(j, i)) {ct++;}
        }
    }

    cout << ct << endl;
}