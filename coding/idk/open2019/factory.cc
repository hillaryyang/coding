//http://www.usaco.org/index.php?page=viewproblem2&cpid=940
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#define ll long long
#define pb push_back
#define f first 
#define mp make_pair
using namespace std;

int n, x, y; 
vector<set<int> > a(101);

bool check(int x) {
    if (a[x].empty()) return false;

    int ct = 1;
    for (auto it : a[x]) {
        //if (x == 2) cout << ct << " "<< it << endl;
        if (ct != x && it != ct) return false;
        ct++;
    }
    
    //if (x == 1) cout << ct << endl;

    if (ct == n + 1) return true;
    return false;
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y; a[y].insert(x);
    }

    for (int z = 0; z < 10; z++) {
        for (int i = 1; i <= n; i++) {
            for (auto j : a[i]) {
                for (auto k : a[j]) a[i].insert(k);
            }

            //for (int i = 1; i <= n; i++) { for (auto it : a[i]) cout << it << " "; cout << endl;
        }
    }

    //for (int i = 1; i <= n; i++) {cout << i << ": "; for (auto it : a[i]) cout << it << " "; cout << endl;}

    for (int i = 1; i <= n; i++) {
        a[i].insert(i);
        if (check(i)) {cout << i << endl; return 0;}
    }

    cout << -1 << endl;
}