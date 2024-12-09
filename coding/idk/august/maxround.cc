//https://codeforces.com/contest/1857/problem/B
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    string s;

    while (t--) {
        cin >> s;

        int k = s.length(), loc = k;
        string t = s;

        if (s[0] >= '5') {
            cout << 1;
            for (int i = 0; i < k; i++) cout << 0;
            cout << endl;
            continue;
        }

        for (int i = k - 2; i >= 0; i--) {
            if (s[i] == '9') {
                if (s[i - 1] != '9' || i == 0) {s[i - 1]++; s[i] = '0'; loc = i;}
            }

            else if (s[i + 1] - '0' >= 5) {s[i]++; loc = i;}
        }

        if (s[0] >= '5') {
            cout << 1;
            for (int i = 0; i < k; i++) cout << 0;
            cout << endl;
            continue;
        }

        for (int i = loc + 1; i < k; i++) s[i] = '0';
        cout << s << endl;
    }
}