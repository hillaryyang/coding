#include <iostream>
#include <cstring>
using namespace std;

int n, m, x, s[30], e[30], cool[110], cost[15], a[15], b[15], p[15], mn = 1e6;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i] >> x; s[i]--; e[i]--;
        for (int j = s[i]; j <= e[i]; j++) cool[j] = max(cool[j], x);
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> p[i] >> cost[i]; a[i]--; b[i]--;
    }
    
    for (int i = 0; i <= 1 << m; i++) {
        int cur = i, temp[110], ct = 0, co = 0; 
        memset(temp, 0, sizeof(temp));

        while (cur) {
            bool on = cur & 1;
            if (on) {
                for (int j = a[ct]; j <= b[ct]; j++) temp[j] += p[ct];
                co += cost[ct];
            }

            ct++; cur >>= 1;
        }

        bool ok = true;
        for (int j = 0; j < n; j++) {
            for (int k = s[j]; k <= e[j]; k++) if (temp[k] < cool[k]) {ok = false; break;}
        }
        
        if (ok) mn = min(mn, co);
    }

    cout << mn << endl;
}