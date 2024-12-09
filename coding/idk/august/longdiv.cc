//https://codeforces.com/problemset/problem/1855/B
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 5e6 + 10;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, ct = 1; cin >> n;

        while (n % (ct + 1) == 0) ct++;

        cout << ct << endl;
    }
}