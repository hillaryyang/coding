#include <iostream>
#include <cstring>
using namespace std;

int n, m, s, t, c, a, b, p, ans = 1e7;
int stalls[110], cost[12], ac[12][2], temp[12];

int main() {
    memset(stalls, 0, sizeof(stalls));
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s >> t >> c;
        for (int j = s; j <= t; j++) stalls[j] = c;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> temp[i] >> cost[i];
        ac[i][0] = a; ac[i][1] = b;
    }
    
    for (int i = 0; i < 1 << m; i++) {
        //these represent the different configs of on/off stalls
        int c = 0, bit_str = i, ct = m - 1, tmp[110];

        memset(tmp, 0, sizeof(tmp));

        while (bit_str) {
            int on = bit_str & 1;
            if (on) {
                //if this stall is on then add the cost to the running total
                c += cost[ct];

                //then we reduce each of these stalls by the value stored in temp
                for (int j = ac[ct][0]; j <= ac[ct][1]; j++) tmp[j] += temp[ct];
            }

            //and modify bit_str and ct
            bit_str >>= 1;
            ct--;
        }

        bool flag = true;
        for (int j = 0; j < 110; j++) {
            if (stalls[j] > tmp[j]) {flag = false; break;}
        }

        if (flag) ans = min(ans, c);
    }

    cout << ans << endl;
}