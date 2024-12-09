//https://codeforces.com/contest/1791/problem/A
#include <iostream>
using namespace std;

int main() {
    int t; char c; cin >> t;
    string s = "codeforces";

    while (t--) {
        cin >> c;

        bool ok = false;
        for (int i = 0; i < 10; i++) {
            if (c == s[i]) {ok = true; break;}
        }

        if (ok) cout << "YES" << endl;
        else cout <<"NO" << endl;
    }
}