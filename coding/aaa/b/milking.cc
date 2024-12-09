/*
ID: hillary3
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > t, res;
int a, b, big, gap, n;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        t.push_back(make_pair(a, b));
    }

    sort(t.begin(), t.end());

    int left = t[0].first, right = t[0].second;

    for (int i = 1; i < n; i++) {
        if (t[i].first >= left && t[i].second <= right) continue;
        else if (t[i].first <= right) right = t[i].second;
        else {
            res.push_back(make_pair(left, right));
            if (right-left > big) big = right - left;

            left = t[i].first; right = t[i].second;
        }
    }

    res.push_back(make_pair(left, right));
    if (right-left > big) big = right - left;

    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i+1].first - res[i].second > gap) gap = res[i+1].first - res[i].second;
    }

    cout << big << " " << gap << endl;
}   