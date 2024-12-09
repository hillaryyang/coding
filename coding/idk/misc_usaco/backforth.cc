//http://www.usaco.org/index.php?page=viewproblem2&cpid=857
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define mp make_pair
#define ll long long
#define pb push_back
const int N = 10;
using namespace std;

vector<int> a, b;
set<int> pos;

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    
    a.resize(N); b.resize(N);

    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    //same bucket all 4 times
    pos.insert(0); 

    //same bucket for 2 times
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) pos.insert(b[j] - a[i]);
    }

    //for (auto i : pos) cout << i << " "; cout << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    if (j != l && i != k) pos.insert(b[j] + b[l] - a[i] - a[k]);
                }
            }
        }
    } 

    //for (auto i : pos) cout << i << " "; cout << endl;

    cout << pos.size() << endl;
}