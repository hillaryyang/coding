//http://www.usaco.org/index.php?page=viewproblem2&cpid=1255
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 1e5 + 10;
using namespace std;

bool st[N]; vector<int> p;

void getprimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) p.pb(i);

        for (int j = 0; p[j] <= n / i; j++) {
            st[p[j] * i] = true;
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
    getprimes(N);

    //for (int i = 0; i < 10; i++) cout << p[i] << " "; cout << endl;

    int x = 11;

    auto up = upper_bound(p.begin(), p.end(), x);

    cout << p[up - p.begin() - 1] << endl;
}