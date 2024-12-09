#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int mn = 0, mx = 0; 

    int cur = 0;
    while (cur < n) {
        if (s[cur] == 'F') {cur++; continue;}

        int nex = cur + 1;
        while (nex < n && s[nex] == 'F') nex++;
        if (nex == n) break;

        int num = nex - cur - 1;

        if (s[nex] == s[cur]) {
            int len = num + 2;

            if (len % 2 == 0) mn++;

            mx += len - 1;
        }

        else {
            int len = num + 2;

            if (len % 2 == 1) mn++;
            mx += len - 2; 
        }

        cur = nex;
    }

    int beg = 0, en = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') beg++; 
        else break;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'F') en++;
        else break;
    }

    if (beg == n) {mn = 0; mx = n - 1;}
    else {mx += beg; mx += en;}

    vector<int> pos;
    if (beg == 0 && en == 0) {
        assert((mx - mn) % 2 == 0);
        for (int i = mn; i <= mx; i += 2) pos.push_back(i);
    }

    else {
        for (int i = mn; i <= mx; i++) pos.push_back(i);
    }

    cout << pos.size() << endl;
    for (auto c : pos) cout << c << endl;
}