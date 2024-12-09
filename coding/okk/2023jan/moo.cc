#include <iostream>
using namespace std;

int n;
string s[101];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++) {
        string cur = s[i];

        if (cur.length() < 3) cout << -1 << endl;

        else if (cur.length() == 3) {
            if (cur == "MOO") cout << 0 << endl;

            else if (cur == "OOO" || cur == "MOM") cout << 1 << endl;

            else if (cur == "OOM") cout << 2 << endl;

            else cout << -1 << endl;
        }

        else {
            int len = cur.length();
            for (int j = 0; j < cur.length() - 3; j++) {
                string x = "";

                x += cur[j]; x += cur[j+1]; x += cur[j+2];

                if (x == "MOO") len = min(len, (int) cur.length() - 3);

                else if (x == "OOO" || x == "MOM") len = min(len, (int) cur.length() - 2);

                else if (x == "OOM") len = min(len, (int) cur.length() - 1);
            }

            if (len == cur.length()) cout << -1 << endl;
            else cout << len << endl;
        }
    }
}