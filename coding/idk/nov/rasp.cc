//https://codeforces.com/problemset/problem/1883/C
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k, x, min1, min2; vector<int> a;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

        if (k == 2 || k == 3 || k == 5) {
            vector<int> to;
            for (int i : a) {
                to.pb((k - (i % k))%k);
            }

            //for (int i : to) cout << i << " "; cout << endl;
            sort(to.begin(), to.end()); 
            cout << to[0] << endl;
        }

        else {
            //either +1 till next multiple of 4
            //or get two 2s, find minimum of these two cases
            vector<int> to;
            for (int i : a) to.pb((4 - (i % 4))%4);
            sort(to.begin(), to.end()); 
            min1 = to[0];

            to.clear();
            for (int i : a) to.pb((2 - (i % 2))%2);
            sort(to.begin(), to.end()); 
            //for (int i : to) cout << i << " "; cout << endl;
            min2 = to[0] + to[1];

            cout << min(min1, min2) << endl;
        }
    }
}