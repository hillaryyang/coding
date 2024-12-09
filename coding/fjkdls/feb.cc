#include <iostream>
#include <vector>
using namespace std;

int n, mn, mx, cur, beg, en;

int main() {
    cin >> n;
    string s; cin >> s;

    while (cur < n) {
        if (s[cur] == 'F') {cur++; continue;}

        int nx = cur + 1;

        while (s[nx] == 'F' && nx < n) nx++;
        if (nx == n) break;

        int numf = nx - cur - 1;
        int len = numf + 2;

        //start and end are the same
        if (s[cur] == s[nx]) {
            if (len % 2 == 0) mn++;
            mx += len - 1;
        }

        //start and end are different
        else {
            if (len % 2 == 1) mn++;
            mx += len - 2;
        }

        cur = nx;
    }

    //count beginning f
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') beg++; 
        else break;
    }

    //count ending f
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'F') en++; 
        else break;
    }

    if (beg == n) {mn = 0; mx = n - 1;}
    else {mx += beg + en;}

    vector<int> pos;
    if (beg == 0 && en == 0) {
        for (int i = mn; i <= mx; i += 2) pos.push_back(i);
    }

    else {
        for (int i = mn; i <= mx; i ++) pos.push_back(i);
    }

    cout << pos.size() << endl;
    for (auto a : pos) cout << a << endl;
}