//https://codeforces.com/contest/1800/problem/C2
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll t, n, x, ans;

int main() {
    cin >> t;

    vector<int> s(n);

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {cin >> x; s.push_back(x);}

        ll open = 0, used = 0, tot = 0;

        while (s[0] == 2 && !s.empty()) s.erase(s.begin());

        //for (auto c : s) cout << c << " "; cout << endl;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 1) {
                if (open != 0) open--;
                tot++; used++;
            }

            else {
                int worst = (tot + 2)/2;
                open += (used - worst);
                used = worst; 
            }

            //cout << i << " " << open << " " << used << " " << tot << endl;
        }

        cout << used + open << endl;
        s.clear();
    }
}