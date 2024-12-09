#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, c, x, sum = 0, ct = 0; cin >> n >> c;
        vector<ll> a, cost;
        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        for (int i = 0; i < n; i++) cost.push_back(a[i] + i + 1);
        
        sort(cost.begin(), cost.end());

        for (int i = 0; i < n; i++) {
            if (sum + cost[i] <= c) {sum += cost[i]; ct++;}
        }

        cout << ct << endl;
    }
}