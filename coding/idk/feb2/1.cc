#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#define pb push_back
using namespace std;

int main() {
    int t, n, x;
    
    cin >> t;
    while (t--) {
        vector<int> hay, w;
        set<int> works;
        cin >> n;

        for (int i = 0; i < n; i++) {cin >> x; hay.pb(x);}

        for (int i = 1; i < n; i++) {
            if ((hay[i] == hay[i - 1])) works.insert(hay[i]);
            else if (i >= 2 && (hay[i] == hay[i - 2])) works.insert(hay[i]);
        }

        if (!works.empty()) {
            for (auto it = works.begin(); it != works.end(); it++) w.pb(*it);
            sort(w.begin(), w.end());
            for (int i = 0; i < w.size() - 1; i++) cout << w[i] << " ";
            cout << w.back() << endl;
        }

        else cout << -1 << endl;
    }
}