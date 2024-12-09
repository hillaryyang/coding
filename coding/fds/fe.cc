#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int n, mn, mx, cur, beg, en;
string s;

int main() {
    cin >> n >> s;

    while (cur < n) {
        if (s[cur] == 'F') {cur++; continue;}

        int nex = cur + 1;

        while (nex < n && s[nex] == 'F') nex++;
        if (nex == n) break;

        int num = nex - cur - 1;;

        if (s[cur] == s[nex]) {
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

    //number of Fs at the front
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
        assert((mn-mx) % 2 == 0);
        for (int i = mn; i <= mx; i+=2) pos.push_back(i);
    }

    else {
        for (int i = mn; i <= mx; i++) pos.push_back(i);
    }

    cout << pos.size() << endl;
    for (auto c : pos) cout << c << endl;
}