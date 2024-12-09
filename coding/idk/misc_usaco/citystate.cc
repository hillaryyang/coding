//http://www.usaco.org/index.php?page=viewproblem2&cpid=667
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define mp make_pair
#define ll long long
#define pb push_back
const int N = 2e5;
using namespace std;

int n, ct = 0;
multimap<string, string> m;

int main() {
    freopen("citystate.in", "r", stdin);  
    freopen("citystate.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string a = "", b, temp;
        cin >> temp >> b;
        a += temp[0]; a += temp[1];

        //cout << a << " " << b << endl;
        //if b maps to a
        if (a != b) {
            auto it1 = m.lower_bound(b), it2 = m.upper_bound(b);

            while (it1 != it2) {
                if (it1 -> first == b && it1 -> second == a) {ct++;}
                it1++;
            }

            m.insert(mp(a, b));
        }
    }

    //for (auto i : m) cout << i.first << " " << i.second << endl;

    cout << ct << endl;
}