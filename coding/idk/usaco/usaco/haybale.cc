//http://www.usaco.org/index.php?page=viewproblem2&cpid=104
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, x, y, ct[1000010];

int main() {
    cin >> n >> k;

    vector<int> pref;

    for (int i = 0; i < k; i++) {
        cin >> x >> y; 
        ct[x]++; ct[y + 1]--;
    }

    for (int i = 1; i <= 7; i++) cout << ct[i] << " "; cout << endl;

    pref.push_back(ct[1]);
    for (int i = 1; i < n; i++) pref.push_back(pref[i - 1] + ct[i + 1]);
    sort(pref.begin(), pref.end());

    cout << pref[pref.size()/2] << endl;
}