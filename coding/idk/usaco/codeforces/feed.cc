#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k; string s; cin >> n >> k >> s;

        char ans[n + 3]; memset(ans, '\0', sizeof(ans));

        for (int i = 0; i < n; i++) {
            if (s[i] == 'G') {
                if (i + k < n) ans[i + k] = 'G';
                else ans[i] = 'G';
                i += 2 * k;
            }
        }

        /*for (int i = 0; i < n; i++) {
            if (ans[i] == 'G') cout << 'G';
            else cout << '.';
        }
        cout << endl;*/

        for (int i = 0; i < n; i++) {
            if (s[i] == 'H') {
                if (i + k < n) {
                    if (ans[i + k] != 'G') ans[i + k] = 'H';
                    else ans[i + k - 1] = 'H';
                    i += 2 * k;
                }

                else {
                    if (ans[i] != 'G') ans[i] = 'H';
                    else ans[i - 1] = 'H';
                    i += 2 * k;
                }
            }
        }

        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] != 'G' && ans[i] != 'H') {ans[i] = '.'; ct++;}
        }

        cout << n - ct << endl;
        for (int i = 0; i < n; i++) cout << ans[i];
        cout << endl;
    }
}