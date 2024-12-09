//https://codeforces.com/contest/1796/problem/B
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;

        int s1, s2, e1, e2;

        if (a[0] == b[0]) {
            string ans = "";
            ans += a[0]; ans += "*";
            cout << "Yes" << endl << ans << endl;
            continue;
        }

        else if (a[a.length() - 1] == b[b.length() - 1]) {
            string ans = "";
            ans += "*"; ans += a[a.length() - 1];
            cout << "Yes" << endl << ans << endl;
            continue;
        }

        //find longest common substring
        string mx = "", cur = "";;
        for (int i = 0; i < a.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                int k = 0;
                while ((i + k) < a.length() && (j + k) < b.length()
                && a[i + k] == b[j + k]) {cur += a[i + k]; k++;}

                if (cur.length() > mx.length()) mx = cur; 
                cur = "";
            }
        }

        if (mx.length() <= 1) cout << "No" << endl;
        else cout << "Yes" << endl << "*" + mx + "*" << endl;
    }
}