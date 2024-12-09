#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> front, back;
        set<char> a;

        for (int i = 0; i < n; i++) {
            a.insert(s[i]); front.push_back(a.size());
        }

        a.clear();

        for (int i = n - 1; i >= 0; i--) {a.insert(s[i]); back.push_back(a.size());}

        reverse(back.begin(), back.end());

        int mx = 0;
        for (int i = 0; i < n - 1; i++) {
            mx = max(mx, front[i] + back[i + 1]);
        }

        /*for (int i : front) cout << i << " "; cout << endl;
        for (int i : back) cout << i << " "; cout << endl;*/

        cout << mx << endl;
    }
}