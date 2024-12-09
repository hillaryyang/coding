/*
ID: hillary3
TASK: transform
LANG: C++                 
*/

#include <iostream>
using namespace std;

int n, before[10][10], after[10][10];
bool t[7], t5[3];
string s;

//90 degree rotation: j, n-i-1
//180 degree rotation: n-i-1, n-i-1
//270 degree rotation: n-i-1, j
//reflection: i, n-j-1,

bool same() {
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (before[i][j] == after[i][j]) ok = true;
            else return 0;
        }
    }

    if (ok) return 1;
    return 0;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) before[i][j] = s[j];
    }


    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) after[i][j] = s[j];
    }

    bool ok = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (before[i][j] != after[j][n-i-1]) t[0] = true;
            if (before[i][j] != after[n-i-1][n-j-1]) t[1] = true;
            if (before[i][j] != after[n-j-1][i]) t[2] = true;

            if (before[i][j] != after[i][n-j-1]) t[3] = true;

            if (before[i][j] != after[n-j-1][n-i-1]) t5[0] = true;
            if (before[i][j] != after[n-i-1][j]) t5[1] = true;
            if (before[i][j] != after[j][i]) t5[2] = true;
        }
    }

    if (t[0] == false) {cout << "1" << endl; return 0; }
    else if (t[1] == false) {cout << "2" << endl; return 0; }
    else if (t[2] == false) {cout << "3" << endl; return 0; }

    else if (t[3] == false) {cout << "4" << endl; return 0; }

    for (auto c : t5) {if (c == false) {cout << "5" << endl; return 0;}}

    if (same()) {cout << "6" << endl; return 0; }

    cout << "7" << endl;
}