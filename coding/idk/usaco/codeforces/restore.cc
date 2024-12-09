//https://codeforces.com/contest/1811/problem/C
#include <iostream>
#include <vector>
using namespace std;

int t, n, x;
vector<int> a, b;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n - 1; i++) {cin >> x; b.push_back(x);}

        a.push_back(b[0]); 
        b.push_back(1e9);

        for (int i = 0; i < n - 1; i++) {
            if (b[i] < b[i + 1]) a.push_back(b[i]);
            else if (b[i] > b[i + 1]) a.push_back(b[i + 1]);
            else a.push_back(b[i]);
        }

        for (int c : a) cout << c << " "; 
        cout << endl;

        a.clear(); b.clear();
    }
}