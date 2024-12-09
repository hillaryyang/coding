//https://codeforces.com/contest/1365/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 501;
using namespace std;

int main() {
    int t; cin >> t;
    
    while (t--) {
        int n, x, c1 = 0, c2 = 0;
        vector<int> a, temp;
        cin >> n;

        for (int i = 0; i < n; i++) {cin >> x; a.pb(x); temp.pb(x);}
        
        for (int i = 0; i < n; i++) {
            cin >> x; 
            if (x == 0) c1++;
            else c2++;
        }

        sort(temp.begin(), temp.end());
        //for (int i : a) cout << i << " "; cout << endl;

        bool ok = true;
        for (int i = 0; i < n; i++) if (a[i] != temp[i]) ok = false;
        if (ok) {cout << "YES" << endl; continue;}

        if (c1 != 0 && c2 != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}