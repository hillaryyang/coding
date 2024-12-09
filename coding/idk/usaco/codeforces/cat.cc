//https://codeforces.com/problemset/problem/1800/A
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;

        string t = "";
        for (int i = 0; i < n; i++) t += tolower(s[i]);

        string ans = "";
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            ans += t[i];
            i = j - 1;
        }

        if (ans == "meow") cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}