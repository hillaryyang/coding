#include <iostream>
using namespace std;

int n, ans, e[100001], g1, h1, g2, h2;
string s;

int main(){
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> e[i]; 

    for (int i = 0; i < n; i++) if (s[i] == 'H') {h1 = i; break;}
    for (int i = 0; i < n; i++) if (s[i] == 'G') {g1 = i; break;}
    for (int i = n - 1; i >= 0; i--) if (s[i] == 'H') {h2 = i; break;}
    for (int i = n - 1; i >= 0; i--) if (s[i] == 'G') {g2 = i; break;}

    if (s[0] == 'G') {
        for (int i = 0; i < h1; i++) {
            if (i == 0 && e[i] > g2) ans++;
            else if (e[i] > h1) ans++;
        }
        
        cout << ans << endl;
    }

    else {
        for (int i = 0; i < g1; i++) {
            if (i == 0 && e[i] > h2) ans++;
            else if (e[i] > g1) ans++;
        }
        
        cout << ans << endl;
    }
}
