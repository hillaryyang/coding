//http://www.usaco.org/index.php?page=viewproblem2&cpid=1255
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
    int t; cin >> t;

    //for (int i = 0; i < 10; i++) cout << p[i] << " "; cout << endl;

    getprimes(N);

    while (t--) {
        int n, x, val; vector<int> a, mv; 
        cin >> n;

        for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

        for (int i = 0; i < n; i++) {
            //find the number of moves it takes for someone to win with a[i] cows
            if (a[i] < 4) mv.pb(1);
            else if (a[i] % 4 == 0 || a[i] % 4 == 2) mv.pb(a[i]/2);
            else {
                auto up = upper_bound(p.begin(), p.end(), a[i]);
                int loc = up - p.begin() - 1;

                while (loc >= 0 && p[loc] % 4 != a[i] % 4) loc--;

                mv.pb((a[i] - p[loc])/2 + 1);
            }
        }

        //for (int i = 0; i < n; i++) cout << mv[i] << " "; cout << endl;

        int mn = 0x3f3f3f3f, win = -1;
        for (int i = 0; i < n; i++) {
            if (mv[i]/2 < mn) {
                mn = mv[i]/2;
                if (a[i] % 4 == 0) win = 1;
                else win = 0;
            }
        }

        //cout << mn << endl;

        if (win == 0) cout << "Farmer John" << endl;
        else cout << "Farmer Nhoj" << endl;
    }
}