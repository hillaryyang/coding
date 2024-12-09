//https://codeforces.com/contest/1832/problem/A
#include <iostream>
#include <vector>
using namespace std;

int t, ct[26];

int main() {
    cin >> t;

    while (t--) {
        string s; cin >> s;
        int num = 0;

        for (int i = 0; i < 26; i++) ct[i] = 0;
        for (int i = 0; i < s.length(); i++) ct[s[i] - 'a']++;
        for (int i = 0; i < 26; i++) if (ct[i] != 0) num++;

        if (num == 1) cout << "NO" << endl;
        else if (num == 2) {
            bool flag = true;
            for (int i = 0; i < 26; i++) if (ct[i] == 1) {flag = false; break;}

            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
}