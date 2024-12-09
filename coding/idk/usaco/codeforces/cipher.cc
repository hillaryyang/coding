//https://codeforces.com/contest/1840/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; string s, a = "";
        cin >> n >> s;

        for (int i = 0; i < n; i++) {
            a += s[i];
            //cout << i << " " << s[i] << endl;
            int loc;
            for (int j = i + 1; j < n; j++) if (s[i] == s[j]) {loc = j; break;}
            i = loc;
            //cout << loc << endl;
        }

        cout << a << endl;
    }
}