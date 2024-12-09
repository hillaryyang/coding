#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

typedef pair<int,int> p;
int n, k;

int main() {
    cin >> n >> k;

    vector <ll> d(n), g(n);

    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end());

    for(int i = 1; i < n; i++) g[i] = d[i] - d[i-1] + 1;

    vector <p> res;
    ll s = d[0], e = d[0], cost = 0; 

    for (int i = 1; i < n; i++) {
        if (g[i] <= 2+k) e = d[i];
        
        else {
            cost += e - s + 1 + k;
            s = e = d[i];
        }
    }
    
    cost += e - s + 1 + k;
    cout << cost << endl;
}