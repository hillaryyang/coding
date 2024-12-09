/*
ID: hillary3
TASK: beads
LANG: C++                 
*/

#include <iostream>
using namespace std;

int n, big; string b, temp;

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    cin >> n >> temp;

    b += temp; b += temp; b += temp;

    for (int i = n; i < 2 * n; i++) {
        bool flag = true;
        int rct = 1, lct = 1;
        char f1 = 'z', f2 = 'z';

        for (int j = i + 1; j < 2 * n + i - n; j++) {
            if (flag) {
                if (b[j] == 'w' || b[j] == f1) {rct++; flag = true;}
                else if (b[j] != 'w' && f1 == 'z') f1 = b[j];
                else {flag = false; break;}
            }

        }

        flag = true;

        for (int j = i; j >= i - n; j--) {
            if (flag) {
                if (b[j] == 'w' || b[j] == f2) {lct++; flag = true;}
                else if (b[j] != 'w' && f2 == 'z') f2 = b[j];
                else {flag = false; break;}
            }
        }

        if (lct + rct > big) {big = lct + rct;}
    }

    if (big > n) cout << n << endl;
    else cout << big << endl;
}