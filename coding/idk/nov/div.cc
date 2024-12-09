//https://codeforces.com/problemset/problem/1881/D
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
const int N = 1010;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, x; map<int, int> facts;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x; 

            while (x % 2 == 0) {
                facts[2]++; x /= 2;
            }

            for (int i = 3; i <= sqrt(x); i += 2) {
                while (x % i == 0) { facts[i]++; x /= i; }
            }

            if (x > 2) facts[x]++;
        }

        bool ok = true;

        for (auto i : facts) {
            if (i.second % n != 0) {cout << "NO" << endl; ok = false; break;}
        }

        if (ok) cout << "YES" << endl;
    }
}