//https://codeforces.com/contest/1791/problem/B
#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int x = 0, y = 0;
        bool ok = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;
            else if (s[i] == 'R') x++;
            else x--;

            if (x == 1 && y == 1) {ok = true; break;}
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}