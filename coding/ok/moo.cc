#include <iostream>
#include <algorithm>
using namespace std;

int q;
string s[101];

int main() {
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s[i];

        string cur = s[i];

        if (s[i].length() < 3) cout << -1 << endl;

        else if (s[i].length() == 3) {
            if (s[i] == "MOO") cout << 0 << endl;
            else if (s[i] == "OOO" || s[i] == "MOM") cout << 1 << endl;
            else if (s[i] == "OOM") cout << 2 << endl;
            else cout << -1 << endl;
        }

        else {
            int small = s[i].length();

            for (int j = 0; j <= s[i].length() - 3; j++) {
                string t;

                t += cur[j]; t += cur[j+1]; t += cur[j+2];

                //cout << t << endl;

                if (t == "MOO") {if (s[i].length() - 3 < small) small = s[i].length() - 3;}
                else if (t == "OOO" || t == "MOM") {if (s[i].length() - 2 < small) small = s[i].length() - 2;}
                else if (t == "OOM") {if (s[i].length() - 1 < small) small = s[i].length() - 1;}

                t = "";
            }

            if (small == s[i].length()) cout << "-1" << endl;
            else cout << small << endl;
        }
    }
}