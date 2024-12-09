#include <iostream>
#include <vector>
using namespace std;

int n, biggap, smallgap, ans, start, bst;
vector <int> loc, a;
string s, t;

// Returns size of largest gap between two 1s and also the index where it starts
int big(string s, int &st) {
    int big = 0; loc.clear();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') loc.push_back(i);
    }

    for (int i = 0; i < loc.size(); i++) {
        if (loc[i+1] - loc[i] > big) {
            big = loc[i+1] - loc[i];
            st = loc[i];
        }
    }
    return big;
}

// Returns size of smallest gap between two 1s
int sm(string s) {
    a.clear();
    int small = 1000001;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') a.push_back(i);
    }

    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i+1] - a[i] < small) small = a[i+1] - a[i];
    }

    return small;
}

//returns the biggest distance between two cows?
int tr(string t) {
    if (big(t, start) >= 2) {
        int bigg = big(t, start);
        t[start + bigg /2] = '1';
        return sm(t);
    }
    return -1;
}

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    cin >> n >> s;

    int biggap = big(s, bst);

    // Possibility 1. put two cows in largest interior gap
    if (big(s, bst) >= 3) {
        t = s;
        t[bst + biggap/3] = '1';
        t[bst + biggap * 2/3] = '1';
        ans = max(ans, sm(t));
    }

    // Possibility 2. cows at both ends
    if (s[0] == '0' && s[n-1] == '0') {
        t = s;
        t[0] = '1'; t[n-1] = '1';
        ans = max(ans, sm(t));
    }

    // Possibility 3. cow at left + cow in largest interior gap
    if (s[0] == '0') {
        t = s;
        t[0] = '1'; 
        ans = max(ans, tr(t));
    }

    //cow at right and largest
    if (s[n-1] == '0') {
        t = s;
        t[n-1] = '1'; 
        ans = max(ans, tr(t));
    }

    // Possibility 5. cow at largest interior gap.  done twice.
    if (big(s, bst) >= 2) {
        t = s; t[bst + biggap/2] = '1';
        ans = max(ans, tr(t));
    }
    
    cout << ans << endl;
}

