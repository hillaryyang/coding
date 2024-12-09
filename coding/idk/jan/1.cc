#include <iostream>

using namespace std;

int n, ansg, ansh, e[100001], g1, h1, g2, h2;
string s;

int main(){
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> e[i];

    for (int i = 0; i < n; i++) if (s[i] == 'H') {h1 = i; break;}
    for (int i = 0; i < n; i++) if (s[i] == 'G') {g1 = i; break;}
    for (int i = n - 1; i >= 0; i--) if (s[i] == 'H') {h2 = i; break;}
    for (int i = n - 1; i >= 0; i--) if (s[i] == 'G') {g2 = i; break;}

    if (e[g1] >= g2) ansg++; //g1leader=true;
    if (e[h1]>=h2) ansh++; //h1leader=true;

    if (g1 < h1) { 
        for (int i = 0; i < h1; i++) {
            if (e[i] > h1 && e[h1] >= h2) ansg++;
        }
    }

     if (g1 > h1) {
        for (int i = 0; i < g1; i++) {
            if (e[i] > g1 && e[g1] >= g2) ansh++;
        }
    }


    cout << ansg*ansh << endl;
}