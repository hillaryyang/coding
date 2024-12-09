#include <iostream>
#include <vector>
using namespace std;

int mx, mn, beg, en;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int cur = 0;
    while (cur < n) {
        //finding the start of a substring
        if (s[cur] == 'F') {cur++; continue;}

        //nex is initially just the character directly proceeding cur
        int nex = cur + 1;

        /*if cur is the start of our substring, 
        nex is the end. we're finding nex here
        by looping thru until we hit another char that isn't F*/
        while (nex < n && s[nex] == 'F') nex++;
        if (nex == n) break;

        //the number of F's is nex - cur - 1
        //the total length is the above value + 2 for the ends
        int numf = nex - cur - 1;
        int len = numf + 2;

        //case 1, start == end
        if (s[cur] == s[nex]) {
            if (len % 2 == 0) mn++;
            mx += len - 1;
        }

        //case 2, start != end
        else {
            if (len % 2 == 1) mn++;
            mx += len - 2;
        }
        
        cur = nex;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') beg++; 
        else break;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'F') en++;
        else break;
    }

    if (beg == n) {mn = 0; mx = n - 1;}
    else mx += beg + en;

    vector<int> pos;
    
    if (beg == 0 && en == 0) {
        for (int i = mn; i <= mx; i += 2) pos.push_back(i);
    }

    else {
        for (int i = mn; i <= mx; i++) pos.push_back(i);
    }

    cout << pos.size() << endl;
    for (int c : pos) cout << c << endl;
}