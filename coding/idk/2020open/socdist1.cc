//http://www.usaco.org/index.php?page=viewproblem2&cpid=1035
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

int main() {
    /*freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);*/

    int n; string s; cin >> n >> s;

    string temp = s;

    bool ok = false;
    for (char c : s) if (c == '1') ok = true;
    if (!ok) {cout << n - 1 << endl; return 0;}

    if (s[0] != '1') s.insert(0, 1, '1');
    if (s.back() != '1') s += '1';

    //cout << s << endl;

    int ct = 0; vector<int> val; 
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') ct++;
        else {val.pb(ct); ct = 0;}
    }

    sort(val.begin(), val.end(), greater<int>());
    //for (int i : val) cout << i << " "; cout << endl;

    int ans1 = round((double)val[0]/3);
    int ans2 = max(ceil((double)val[0]/2), ceil((double)val[1]/2));
    //cout << ans1 << " " << ans2 << endl;
    if (val.size() == 2 && temp[0] == '1' && temp[n - 1] == '1') cout << ans1 << endl;
    else if (val.size() == 2 && ((temp[0] == '1' && temp[n - 1] == '1')
    || (temp[0] == '0' && temp[n - 1] == '1'))) cout << floor((double)val[0]/2) << endl;
    else cout << max(ans1, ans2) << endl;
}