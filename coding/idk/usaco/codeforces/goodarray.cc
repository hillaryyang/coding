//https://codeforces.com/problemset/problem/1838/B
#include <iostream>
using namespace std;

int t, n, k, loc_n, a, b;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> p;

        for (int i = 0; i < n; i++) {
            cin >> k; p.push_back(k);
            if (k == n) loc_n = i + 1;
            else if (k == 1) a = i + 1;
            else if (k == 2) b = i + 1;
        }

        //cout << a << " " << b << " " << loc_n << endl;

        if ((loc_n > a && loc_n < b)
        || (loc_n < a && loc_n > b)) cout << 1 << " " << 1 << endl;
        
        else if (loc_n > a && loc_n > b) {
            if (a > b) cout << a << " " << loc_n << endl;
            else cout << b << " "<< loc_n << endl;
        }

        else {
            if (a > b) cout << b << " " << loc_n << endl;
            else cout << a << " "<< loc_n << endl;
        }
    }
}