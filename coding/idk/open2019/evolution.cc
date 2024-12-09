//http://www.usaco.org/index.php?page=viewproblem2&cpid=941
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define f first 
#define mp make_pair
using namespace std;

int n, k; string s; vector<vector<string> > traits(30);
vector<string> used;

string mostcom(vector<vector<string> > x) {
    map<string, int> a; int mx = 0; string com;
    for (int i = 0; i < x.size(); i++) {
        for (string j : x[i]) a[j]++;
    }

    //for (auto it : a) cout << it.first << " " << it.second << endl;

    for (auto it : a) {
        if (it.second > mx) {mx = it.second; com = it.first;}
    }

    return com;
}

bool check(vector<string> x, string y) {
    for (string s : x) if (s == y) return false;
    return true;
}

bool solve(vector<vector<string> > x) {
    if (x.empty()) return true;

    s = mostcom(x);
    if (!check(used, s)) return false;
    used.pb(s);
    //for (string s : used) cout << s << " "; cout << endl;

    vector<vector<string> > a, b;

    for (auto i : x) {
        bool ok = false;
        for (int j = 0; j < i.size(); j++) {
            if (i[j] == s) {
                i.erase(i.begin() + j); 
                if (!i.empty()) a.pb(i); 
                ok = true; break;
            }
        }

        if (!ok && !i.empty()) b.pb(i);
    }

    /*cout << "a: ";
    for (int i = 0; i < a.size(); i++) {
        cout << i << ": "; for (string j : a[i]) cout << j << " "; cout << endl;
    }

    cout << "b: ";
    for (int i = 0; i < b.size(); i++) {
        cout << i << ": "; for (string j : b[i]) cout << j << " "; cout << endl;
    }*/

    return (solve(a) && solve(b));
}

int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        while (k--) {cin >> s; traits[i].pb(s);}
    }

    if (solve(traits)) cout << "yes" << endl;
    else cout << "no" << endl;
}