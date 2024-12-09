//https://codeforces.com/contest/1789/problem/B
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, start, en;

bool pal (string s) {
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }

    return true;
}

int main() {
    string s;

    cin >> t;
    while (t--) {
        cin >> n; cin >> s;

        if (pal(s)) {cout << "YES" << endl; continue;}

        for (int i = 0; i < n; i++) {
            //i corresponds to n - i - 1
            if (s[i] != s[n - i - 1]) {
                start = i, en = i;
                while (en < n/2 && s[en] != s[n - en - 1]) en++;
                break;
            }
        }

        en--;

        for (int i = start; i <= en; i++) {
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
            //cout << "s: " << s << endl;
        }

        //cout << s << endl;

        if (pal(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}