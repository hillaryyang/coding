//http://www.usaco.org/index.php?page=viewproblem2&cpid=1156
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
#define f first
using namespace std;

int main() {
    int n, x, mn = 1e9; cin >> n;
    vector<int> p, t, dif;

    for (int i = 0; i < n; i++) {cin >> x; p.pb(x);}
    for (int i = 0; i < n; i++) {cin >> x; t.pb(x);}

    for (int i = 0; i < n; i++) dif.pb(p[i] - t[i]);
    
    //for (int i : dif) cout << i << " "; cout << endl;

    bool sign = (dif[0] >= 0); int prev = 0, ans = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        if ((dif[i + 1] < 0 && sign) || (dif[i + 1] >= 0 && !sign) || i == n - 1) {
            //cout << i << endl;
            sum += abs(dif[prev]) + abs(dif[i]);
            //cout << i << " " << abs(dif[prev]) + abs(dif[i]) << endl;

            for (int j = prev + 1; j <= i; j++) {
                //cout << j << " " << dif[j] << " " << dif[j - 1] << endl;
                dif[j - 1] = abs(dif[j - 1]); dif[j] = abs(dif[j]);

                sum += (abs(dif[j] - dif[j - 1]));
                //cout << abs(dif[j + 1] - dif[j]) << endl;
            }
            
            //cout << i << " " << sum << endl;
            sign = !sign; prev = i + 1;
        }
    }
    ans += sum/2; 

    cout << ans << endl;
}