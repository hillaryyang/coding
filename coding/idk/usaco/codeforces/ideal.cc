//https://codeforces.com/contest/1795/problem/B
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, k, x, y;

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> k;

        vector<int> l, r;
        int num[51]; memset(num, 0, sizeof(num));

        for (int i = 0; i < n; i++) {
            cin >> x >> y; 
            l.push_back(x); r.push_back(y);

            for (int i = x; i <= y; i++) num[i]++;
        }

        /*for (int i = 0; i < 51; i++) cout << num[i] << " ";
        cout << endl;*/

        for (int i = 0; i < n; i++) {
            //k isn't included in this
            if (k < l[i] || k > r[i]) {
                for (int j = l[i]; j <= r[i]; j++) num[j]--;
            }
        }

        bool ok = true;
        for (int i = 0; i < 51; i++) {
            if (num[k] <= num[i] && k != i) {ok = false; break;}
        }

        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}