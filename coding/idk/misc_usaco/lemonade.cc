//http://www.usaco.org/index.php?page=viewproblem2&cpid=835
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    
    int n; cin >> n;
    vector<int> a; a.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int ct = 0;
    for (int i = 0; i < n; i++) {
        ct += (ct <= a[i]);
    }

    cout << ct << endl;
}