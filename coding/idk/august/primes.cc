//https://codeforces.com/problemset/problem/1857/F
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 1e6;
using namespace std;

vector<int> p;
bool st[N];

int getprimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) p.pb(i);

        for (int j = 0; p[j] <= n / i; j++) {
            st[p[j] * i] = true;
            if (i % p[j] == 0) break;
            //cout << p[j] << " " << p[j] * i << endl;
        }

        //for (int i : p) cout << i << " "; cout << endl;
    }
}

int main() {
    getprimes(N);

   for (int i = 0; i < 10; i++) cout << p[i] << " "; cout << endl;
}