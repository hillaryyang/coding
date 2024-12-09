#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
#define pb push_back
#define f first
#define s second
#define ll long long
#define mp make_pair
const int N = 105;
using namespace std;

ll n, m, x;
vector<ll> cows;

int main() {
    cin >> n >> m;
    cows.resize(n); 

    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 0; i < m; i++) {
        cin >> x;
        ll eaten = 0;

        for (int j = 0; j < n && eaten < x; j++) {
            ll add = max((ll)0, min(x, cows[j]) - eaten);
            //cout << cows[j] << " " << add << endl;
            cows[j] += add; eaten += add;
        }
    }

    for (ll i : cows) cout << i << endl;
}