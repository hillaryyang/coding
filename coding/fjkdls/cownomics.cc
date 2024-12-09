#include <iostream>
#include <algorithm>
using namespace std;

int ct;
string spot[100], plain[100];

bool c (char c, string a, string b) {
    bool aa = false, bb = false;
    for (int i = 0; i < (int) a.length(); i++) {
        if (a[i] == c) aa = true;
        if (b[i] == c) bb = true;
    }

    if (aa == true && bb == true) return true;
    else return false;
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> spot[i];
    for (int i = 0; i < n; i++) cin >> plain[i];

    for (int i = 0; i < m; i++) {
        string s, p;
        for (int j = 0; j < n; j++) s += spot[j][i];
        for (int j = 0; j < n; j++) p += plain[j][i];

        if (c('G', s, p) || c('C', s, p) || c('T', s, p) || c('A', s, p)) continue;
        else ct++;
    }

    cout << ct << endl;
}