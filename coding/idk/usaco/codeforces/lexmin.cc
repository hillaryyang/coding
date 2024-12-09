//https://codeforces.com/contest/1799/problem/C
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;
        int a[26], f = 0, b = 0, n = s.length();
        char ans[n];

        memset (ans, '\0', sizeof(ans));

        sort(s.begin(), s.end());

        for (int i = 0; i < 26; i++) a[i] = count(s.begin(), s.end(), i + 'a');

        //getting the front
        for (int i = 0; i < 26; i++) {
            if (a[i] >= 2) {
                int x = a[i]/2, y = a[i] - x;
                f += x; b += y;

                for (int j = 0; j < y; j++) ans[j] = (char) 'a' + i;
                for (int j = n - 1; j >= n - x; j--) ans[j] = (char) 'a' + i;
                break;
            }
        }


        for (int i = 0; i < 26; i++) {
            if (a[i] > 0) {
                if (a[i] % 2 == 0) {
                    int x = a[i]/2;

                    f += x; b += x;
                }
            }
        }

        for (int i = 0; i < n; i++) cout << ans[i]; cout << endl;
    }
}