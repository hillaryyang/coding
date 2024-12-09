#include <iostream>
using namespace std;

char b[3][3];

bool w1(char c) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == c && b[i][1] == c && b[i][2] == c) return true;
    }
    
    for (int i = 0; i < 3; i++) {
        if (b[0][i] == c && b[1][i] == c && b[2][i] == c) return true;
    } 

    if (b[0][0] == c && b[1][1] == c && b[2][2] == c) return true;
    if (b[0][2] == c && b[1][1] == c && b[2][0] == c) return true;

    return false;
}

bool all(string s) {
    if (s[0] == s[1] && s[1] == s[2]) return true;
    return false;
}

bool w2 (char x, char y) {
    for (int i = 0; i < 3; i++) {
        string cur = ""; cur += b[i][0]; cur += b[i][1]; cur += b[i][2];

        if ((b[i][0] == x || b[i][0] == y) &&
        (b[i][1] == x || b[i][1] == y) &&
        (b[i][2] == x || b[i][2] == y) && !all(cur)) return true;
    }

    for (int i = 0; i < 3; i++) {
        string cur = ""; cur += b[0][i]; cur += b[1][i]; cur += b[2][i];

        if ((b[0][i] == x || b[0][i] == y) &&
        (b[1][i] == x || b[1][i] == y) &&
        (b[2][i] == x || b[2][i] == y) && !all(cur)) return true;
    }

    string cur = "";
    cur += b[0][0]; cur += b[1][1]; cur += b[2][2];
    if (!all(cur) && 
    (b[0][0] == x || b[0][0] == y) &&
    (b[1][1] == x || b[1][1] == y) &&
    (b[2][2] == x || b[2][2] == y)) return true;

    cur = "";
    cur += b[0][2]; cur += b[1][1]; cur += b[2][0];
    if (!all(cur) && 
    (b[0][2] == x || b[0][2] == y) &&
    (b[1][1] == x || b[1][1] == y) &&
    (b[2][0] == x || b[2][0] == y)) return true;

    return false;
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    
    for (int i = 0; i < 3; i++) {
        string s; cin >> s;
        for (int j = 0; j < 3; j++) b[i][j] = s[j];
    }

    //individual
    int one = 0;
    for (int i = 0; i < 26; i++) {
        char cur = 'A' + i;
        if (w1(cur)) one++;
    }

    cout << one << endl;

    //two
    int two = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i; j < 26; j++) {
            char a = 'A' + i, b = 'A' + j;
            if (w2(a, b)) two++;
        }
    }

    cout << two << endl;
}