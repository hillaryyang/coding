#include <iostream>
using namespace std;

int s[101], t[101], b[101];
int ans;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> b[i];
    }

    for (int i = 1; i < 1000; i++) {
        int ct = 0;
        for (int j = 0; j < n; j++) {
            if (i >= s[j] && i <= t[j]) ct += b[j];
        }

        ans = max(ct, ans);
    }

    cout << ans << endl;

}