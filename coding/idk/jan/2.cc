#include <iostream>
using namespace std;

int n, m, stalls[110];
int ac[12][2], temp[12], cost[12];

int main() {
    memset(stalls, 0, sizeof(stalls));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int s, t, c; cin >> s >> t >> c;
        // cout << s << ' ' << t << ' ' << c << endl;
        for (int j = s; j <= t; j++) stalls[j] = c;
    }
    for (int i = 0; i < m; i++) {
        int a, b, p, c; cin >> a >> b >> p >> c;
        ac[i][0] = a; ac[i][1] = b;
        temp[i] = p;
        cost[i] = c;
    }

    int ans = 1e7;
    for (int i = 0; i < 1 << m; i++) {
        int c = 0;
        int bit_str = i, cnt = m - 1;
        int tmp_arr[110];
        memset(tmp_arr, 0, sizeof(tmp_arr));
        while (bit_str) {
            int is_on = bit_str & 1;
            // out << is_on << endl;
            if (is_on) {
                c += cost[cnt];
                for (int j = ac[cnt][0]; j <= ac[cnt][1]; j++) {
                    // cout << "j = " << j << endl;
                    tmp_arr[j] += temp[cnt];
                }
            }
            bit_str >>= 1;
            cnt--;
        }

        bool flag = true;
        for (int i = 0; i < 110; i++) {
            if (stalls[i] > tmp_arr[i]) {
                flag = false;
                break;
            }
        }

        if (flag) ans = min(ans, c);
    }

    cout << ans << endl;
}