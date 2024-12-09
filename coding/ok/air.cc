#include <iostream>
#include <cstring>

using namespace std;

int n, m, ans = 1e7;
int stalls[101], temp[12], cost[12], ac[101][2], tmp[101];

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

        memset (tmp, 0, sizeof(tmp));

        while (bit_str) {
            int on = bit_str & 1;

            if (on) {
                //add the cost to the running total, c
                c += cost[cur];

                //reduce each of the stalls by temp[cur]
                for (int j = ac[cur][0]; j <= ac[cur][1]; j++) tmp[j] += temp[cur];
            }

            cur--; bit_str >>= 1;
        } 

        bool flag = true;
        for (int j = 0; j < 101; j++) {
            if (stalls[j] > tmp[j]) {flag = false; break;}
        }

        if (flag) ans = min(c, ans);
    }

    cout << ans << endl;
}