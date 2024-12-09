#include <iostream>
using namespace std;

int one, two;
char b[3][3];
string s;

bool same(char c) {
    int o = 0;
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == c && b[i][1] == c && b[i][2] == c) return true;
    }

    for (int i = 0; i < 3; i++) {
        if (b[0][i] == c && b[1][i] == c && b[2][i] == c) return true;
    }

    if (b[0][0] == c && b[1][1] == c && b[2][2] == c) return true;
    if (b[1][1] == c && b[2][0] == c && b[0][2] == c) return true;
    return false;
}

bool win(char x, char y) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2]) continue;
        if ((b[i][0] == x || b[i][0] == y) &&
        (b[i][1] == x || b[i][1] == y) &&
        (b[i][2] == x || b[i][2] == y)) return true;
    }

    for (int i = 0; i < 3; i++) {
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i]) continue;
        if ((b[0][i] == x || b[0][i] == y) &&
        (b[1][i] == x || b[1][i] == y) &&
        (b[2][i] == x || b[2][i] == y)) return true;
    }

    if (!(b[0][0] == b[1][1] && b[1][1] == b[2][2])) {
        if ((b[0][0] == x || b[0][0] == y) &&
        (b[1][1] == x || b[1][1] == y) &&
        (b[2][2]==x || b[2][2] == y)) return true;
    }

    if (!(b[2][0] == b[1][1] && b[1][1] == b[0][2])) {
        if ((b[2][0] == x || b[2][0] == y) &&
        (b[1][1] == x || b[1][1] == y) &&
        (b[0][2] == x || b[0][2] == y)) return true;
    }

    return false;
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    for (int i = 0; i < 3; i++) {
        cin >> s;
        for (int j = 0; j < 3; j++) b[i][j] = s[j];
    }

    for (int i = 0; i < 26; i++) if (same(i+'A')) one++;
    
    for (int i = 0; i < 26; i++) {
        for (int j = i+1; j < 26; j++) {
            char m = i + 'A', n = j + 'A';
            if (i != j && win(m, n)) two++;
        }
    }
    
    cout << one << endl << two << endl;
}