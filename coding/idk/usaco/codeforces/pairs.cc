//https://codeforces.com/contest/1800/problem/B
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t, n, k;
    string s;
    cin >> t;

    while (t--) {
        cin >> n >> k >> s;
        int lower[26], upper[26];
        memset(lower, 0, sizeof(lower)); memset(upper, 0, sizeof(upper));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] - 'A' < 26) upper[s[i] - 'A']++;
            else lower[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            int x = min(lower[i], upper[i]);
            ans += x; lower[i] -= x; upper[i] -= x;
        }

        /*for (int i = 0; i < 26; i++) cout << lower[i] << " ";
        cout << endl;

        for (int i = 0; i < 26; i++) cout << upper[i] << " ";
        cout << endl;*/

        int pos = 0;
        for (int i = 0; i < 26; i++) pos += upper[i]/2 + lower[i]/2;

        ans += min(pos, k);

        cout << ans << endl;
    }
}