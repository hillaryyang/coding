//http://www.usaco.org/index.php?page=viewproblem2&cpid=987
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 2e5 + 10;
using namespace std;

int n, k, cur;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    cin >> n >> k;
    string a;
    
    for (int i = 0; i < n; i++) {
        cin >> a;

        if (cur + a.length() <= k) {
            if (cur == 0) cout << a;
            else cout << " " << a;

            cur += a.length();
        }

        else {
            cout << endl << a;
            cur = a.length();
        }
    }
}