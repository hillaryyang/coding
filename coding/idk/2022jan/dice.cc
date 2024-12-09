//http://www.usaco.org/index.php?page=viewproblem2&cpid=1180
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mt make_tuple
#define ll long long
#define f first
#define s second
using namespace std;

int beats(vector<int> a, vector<int> b) {
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] > b[j]) ct1++;
            else break;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (b[i] > a[j]) ct2++;
            else break;
        }
    }

    //cout << ct1 << " " << ct2 << endl;

    if (ct1 == ct2) return 0;
    else if (ct1 > ct2) return 1;
    else return -1;
}

bool solve(vector<int> a, vector<int> b) {
    for (int m = 1; m <= 10; m++) {
        for (int n = m; n <= 10; n++) { 
            for (int o = n; o <= 10; o++) {
                for (int p = o; p <= 10; p++) {
                    vector<int> c; 
                    c.pb(m); c.pb(n); c.pb(o); c.pb(p);
                    if (beats(c, a) == 1 && beats(b, c) == 1) return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int t, n; 
    cin >> t;

    while (t--) {
        vector<int> a, b;

        for (int i = 0; i < 4; i++) {cin >> n; a.pb(n);}
        for (int i = 0; i < 4; i++) {cin >> n; b.pb(n);}

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        //tie
        if (beats(a, b) == 0) {cout << "no" << endl; continue;}

        //make it so a always beats b
        if (beats(b, a) == 1) swap(a, b);
        
        if (solve(a, b)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}