//http://www.usaco.org/index.php?page=viewproblem2&cpid=1203
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
using namespace std;

int n; 
vector<string> b;

bool solve(string s, vector<string> b) {
    for (int i = 0; i < s.length(); i++) {
        //check if b[i] has s[i]
        bool x = false;
        for (char j : b[i]) if (j == s[i]) {x = true; break;}

        if (!x) return false;
    }

    return true;
}

int main() {
    cin >> n;
    string s;
    for (int i = 0; i < 4; i++) {cin >> s; b.pb(s);}
    //for (auto i : b) cout << i << " "; cout << endl;

    while (n--) {
        string s; cin >> s;
        sort(b.begin(), b.end());

        bool ok = false;

        do {
            //for (auto i : b) cout << i << " "; cout << endl;
            if (solve(s, b)) {cout << "YES" << endl; ok = true; break;}
        } while (next_permutation(b.begin(), b.end()));

        if (!ok) cout << "NO" << endl;
    }
}