#include <iostream>
#include <cstring>
using namespace std;

int n, m, stalls[101], temp[12], cost[12], ans = 1e7;
int ac[101][2];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        for (int j = s; j <= t; j++) stalls[j] = c;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b >> temp[i] >> cost[i];
        ac[i][0] = a; ac[i][1] = b;
    }

    for (int i = 0; i < 1 << m; i++) {
        int bit_str = i, cur = m - 1, c = 0;
        int tmp[101];

        memset (tmp, 0, sizeof(tmp));

        while (bit_str) {
            int on = bit_str & 1;

            if (on) {
                c += cost[cur];
                for (int j = ac[cur][0]; j <= ac[cur][1]; j++) tmp[j] += temp[cur];
            }

            bit_str >>= 1;
            cur--;
        }

        bool flag = true;
        for (int j = 0; j < 101; j++) {
            if (stalls[j] > tmp[j]) flag = false;
        }

        if (flag) ans = min(ans, c);
    }

    cout << ans << endl;
}