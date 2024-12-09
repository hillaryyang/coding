#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxsame, c[101], num;
string charac, an;
vector<vector<string> > ch(100);

int same(int a, int b) {
    int ct = 0;

    for (int i = 0; i < c[a]; i++) {
        for (int j = 0; j < c[b]; j++) {
            if (ch[a][i] == ch[b][j]) ct++;
        }
    }

    return ct;
}

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> an >> num;
        c[i] = num;
        for (int j = 0; j < num; j++) {
            cin >> charac;
            ch[i].push_back(charac);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            maxsame = max(maxsame, same(i, j));
        }
    } cout << maxsame + 1 << endl;
}