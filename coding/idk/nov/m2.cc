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
        int n, k, x, ans[(int)1e5 + 10]; cin >> n >> k;
        vector<int> a;

        for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

        int num = k % (n + 1);

        //cout << num << endl;

        //first chunk
        for (int i = 0; i < n - num; i++) ans[num + i]= a[i];

        //different one
        ans[num - 1] = mex(a);

        //for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
        //second chunk
        for (int i = n - num + 1; i < n; i++) ans[i + num - n - 1] = a[i];

        for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
    }
}