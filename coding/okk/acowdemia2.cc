#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int k, n;
map <string, int> c;
char ans[101][101];

int main() {
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        c[x] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) ans[i][j] = 'B';
            else ans[i][j] = '?';
        }
    }

    for (int i = 0; i < k; i++) {
        string ord[101];
        for (int j = 0; j < n; j++) cin >> ord[j];

        for (int x = 0; x < n; x++) {
            bool alph = true;
            for (int y = x + 1; y < n; y++) {
                if (ord[y - 1] > ord[y]) alph = false;

                if (!alph) {
                    int a = c[ord[x]], b = c[ord[y]];
                    ans[a][b] = '0'; ans[b][a] = '1';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        } cout << endl;
    }
}