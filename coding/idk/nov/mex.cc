//https://codeforces.com/problemset/problem/1863/C
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
const int N = 1010;
using namespace std;

int mex(vector<int> a) {
    sort(a.begin(), a.end());
    //for (int i : a) cout << i << " "; cout << endl;

    for (int i = 0; i < a.size(); i++) {
       if (a[i] != i) return i;
    }

    return a.size();
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k, x, num, ct = 0; vector<int> a, temp, m;
        
        cin >> n >> k;
        for (int i = 0; i < n; i++) {cin >> x; a.pb(x); temp.pb(x); m.pb(x);}

        //cout << "original: "; for (int i : temp) cout << i << " "; cout << endl;

        while (n) {
            for (int i = 0; i < n; i++) a[i] = mex(a);
            ct++;

            for (int i : a) cout << i << " "; cout << endl;
            
            bool check = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != temp[i]) {check = false; break;}
            }

            if (check) break;
        }

       // cout << ct << endl;

        if (ct == 0) num = k;
        else num = (k % ct);

        //cout << num << endl;

        while (num--) {  
            for (int i = 0; i < n; i++) m[i] = mex(m);
        }

        //for (int i : m) cout << i << " "; cout << endl;
    }
}