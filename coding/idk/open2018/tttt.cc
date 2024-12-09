//http://www.usaco.org/index.php?page=viewproblem2&cpid=831
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define f first 
#define mp make_pair
using namespace std;

char b[3][3]; string s; int ans = 0;

bool check1(char x, char y, char z, char a) {
    if (x == a && y == a && z == a) return true;
    return false;
}

bool check2(char x, char y, char z, char i, char j) {
    if (check1(x, y, z, i) || check1(x, y, z, j)) return false;
    
    if ((x == i || x == j) && (y == i || y == j) && (z == i || z == j)) return true;
    return false;
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    for (int i = 0; i < 3; i++) {
        cin >> s;
        for (int j = 0; j < 3; j++) b[i][j] = s[j];
    }

    for (int i = 0; i < 26; i++) {
        bool ok = false;

        for (int j = 0; j < 3; j++) {
            if (check1(b[j][0], b[j][1], b[j][2], (char)('A' + i))) ok = true;
        }

        for (int j = 0; j < 3; j++) {
            if (check1(b[0][j], b[1][j], b[2][j], (char)('A' + i))) ok = true;
        }

        if (check1(b[0][0], b[1][1], b[2][2], (char)('A' + i))) ok = true;
        if (check1(b[0][2], b[1][1], b[2][0], (char)('A' + i))) ok = true;

        if (ok) ans++;
    }

    cout << ans << endl;
    ans = 0;

    for (int i = 0; i < 26; i++) {
        for (int k = i + 1; k < 26; k++) {
            bool ok = false;

            for (int j = 0; j < 3; j++) {
                if (check2(b[j][0], b[j][1], b[j][2], (char)('A' + i), (char)('A' + k))) ok = true;
            }

            for (int j = 0; j < 3; j++) {
                if (check2(b[0][j], b[1][j], b[2][j], (char)('A' + i), (char)('A' + k))) ok = true;
            }

            if (check2(b[0][0], b[1][1], b[2][2], (char)('A' + i), (char)('A' + k))) ok = true;
            if (check2(b[0][2], b[1][1], b[2][0], (char)('A' + i), (char)('A' + k))) ok = true;

           // cout << (char)('A' + i) << " " << (char)('A' + k) << " " << ans << endl;
            if (ok) ans++;
        }
    }

    cout << ans << endl;
}