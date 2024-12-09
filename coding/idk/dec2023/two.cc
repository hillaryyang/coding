#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
#define pb push_back
#define f first
#define pii pair<int, int>
#define mp make_pair
const int N = 105;
using namespace std;

int main() {
    int n, ans = 0, mn; string s;
    cin >> n >> s;

    vector<int> cts; int ct = 0;
    for (char i : s) {
        if (i == '1') ct++;
        else if (ct != 0) {cts.pb(ct); ct = 0;}
    } if (ct != 0) cts.pb(ct);

    if (cts.empty()) {cout << 0 << endl; return 0;}
 
    //left and right edge cases
    mn = min(cts[0], cts.back()) - 1;
    if (s[0] == '0') mn = min(mn, (cts[0] - 1)/2);
    if (s.back() == '0') mn = min(mn, (cts.back() - 1)/2);
    //cout << mn << endl;

    if (cts.size() > 2) for (int i = 1; i < cts.size() - 1; i++) mn = min(mn, (cts[i] - 1)/2);
    //cout << mn << endl;

    for (int i : cts) {
        ans += i/(mn * 2 + 1);
        if (i % (mn * 2 + 1) != 0) ans++;
    }

    cout << ans << endl;
}