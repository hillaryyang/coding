#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb push_back
#define ll long long
using namespace std;

int main() {
    int n, k, a, b; 
    cin >> n >> k;

    int ct[n + 10]; memset(ct, 0, sizeof(ct));
    
    while (k--) {
        cin >> a >> b;
        ct[a]++; ct[b + 1]--;
    }

    vector<int> pre;
    pre.pb(ct[0]); 
    for (int i = 1; i < n; i++) pre.pb(ct[i] + pre[i - 1]);

    sort(pre.begin(), pre.end());
    //for (int i : pre) cout << i << " "; cout << endl;
    
    cout << pre[n/2] << endl;
}