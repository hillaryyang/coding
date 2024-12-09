//https://codeforces.com/problemset/problem/1117/C
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
    
ll x, y, x2, y2, n, ans = -1, u, d, le, r, rr, lll, uu, dd;
string s;
    
bool check (ll days) {
    //where is the boat if we just leave it to the wind
    ll len = s.length(), tx = x, ty = y;
    
    uu *= days/len; dd *= days/len; lll *= days/len; rr *= days/len;
    
    for (int i = 0; i < days % len; i++) {
        uu += (s[i] == 'U'); dd += (s[i] == 'D');
        lll += (s[i] == 'L'); rr += (s[i] == 'R');
    }
    
    tx += (rr - lll);
    ty += (uu - dd);
    
    /*cout << uct << " " << dct << " " << rct << " " << lct << endl;
    cout << tx << " " << ty <<endl;*/
    
    if (abs(tx - x2) + abs(ty - y2) <= days) return true;
    return false;
}
    
int main() {
    cin >> x >> y >> x2 >> y2 >> n >> s;
    
    for (char c : s) {
        u += (c == 'U'); d += (c == 'D');
        le += (c == 'L'); r += (c == 'R');
    }
    
    //cout << u << " " << d << " " << le << " " << r << endl;
    
    ll l = 1, h = 1000000000000000;
    
    while (l <= h) {
        ll mid = (l + h)/2;
        uu = u, dd = d, lll = le, rr = r;
    
        if (check(mid)) {h = mid - 1; ans = mid;}
        else l = mid + 1;
    }
    
    cout << ans << endl;
}