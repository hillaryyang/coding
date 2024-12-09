//http://www.usaco.org/index.php?page=viewproblem2&cpid=1179
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mt make_tuple
#define ll long long
#define f first
#define s second
using namespace std;

char ans[3][3], guess[3][3];
string str;
int ans1 = 0, ans2 = 0, a[26], g[26];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> str;
        for (int j = 0; j < 3; j++) {ans[i][j] = str[j]; a[str[j] - 'A']++;}
    }

    for (int i = 0; i < 3; i++) {
        cin >> str;
        for (int j = 0; j < 3; j++) {guess[i][j] = str[j]; g[str[j] - 'A']++;}
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ans[i][j] == guess[i][j]) {
                ans1++; 
                a[ans[i][j] - 'A']--;
                g[ans[i][j] - 'A']--;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (a[i] && g[i]) {
            if (a[i] <= g[i]) ans2 += a[i];
            else ans2 += g[i];
        }
    }

    cout << ans1 << endl << ans2 << endl;
}