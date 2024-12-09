//https://codeforces.com/contest/1851/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define f first 
#define s second 
#define mp make_pair
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, m, k, H, h, ct = 0; cin >> n >> m >> k >> H;

        for (int i = 0; i < n; i++) {
            cin >> h;
            for (int j = k; j <= (m - 1) * k; j += k) {
                if (h + j == H || h - j == H) ct++;
            }
        }

        cout << ct << endl;
    }
}