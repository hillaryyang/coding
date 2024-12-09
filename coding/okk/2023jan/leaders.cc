#include <iostream>
using namespace std;

int n, e[100003], g, h, lg, lh, ans; 
string s;

int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++) {cin >> e[i]; e[i]--;}

    for (int i = 0; i < n; i++) if (s[i] == 'G') {g = i; break;}

    for (int i = 0; i < n; i++) if (s[i] == 'H') {h = i; break;}

    for (int i = n; i >= 0; i--) if (s[i] == 'G') {lg = i; break;}

    for (int i = n; i >= 0; i--) if (s[i] == 'H') {lh = i; break;}

    //guernsey visited everyone
    if (e[g] >= lg) {
        for (int i = 0; i < g; i++) {
            if (i == h) continue;
            if (s[i] == 'H' && e[i] >= g) ans++;
        }       
    }

    //holstein visited everyone
    if (e[h] >= lh) {
        for (int i = 0; i < h; i++) {
            if (i == g) continue;
            if (s[i] == 'G' && e[i] >= h) ans++;
        }
    }

    //g and h are both leaders
    if ((e[g] >= lg || (g < h && e[g] >= h)) && (e[h] >= lh || (h < g && e[h] >= g))) ans++;

    cout << ans << endl;

}