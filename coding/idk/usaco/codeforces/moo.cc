#include <iostream>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;

        int len = s.length(), ans = 1e3;

        for (int i = 0; i < len; i++) {
            string cur = s.substr(i, 3);

            if (cur == "MOO") ans = min(ans, len - 3);
            else if (cur == "MOM" || cur == "OOO") ans = min(ans, len - 2);
            else if (cur == "OOM") ans = min(ans, len - 1);
        }

        if (ans == 1e3) cout << -1 << endl;
        else cout << ans << endl;
    }
}