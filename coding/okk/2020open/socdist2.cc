#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y, ans = 1, sick[1000001], r = 1e6;
vector<pair<int, int> > cows;
vector<int> cap;

int main() {
    cin >> n;

    int id = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cows.push_back(make_pair(x, y));
        if (y == 1) {sick[id] = x; id++;}
    }

    sort(cows.begin(), cows.end());

    //find greatest possible r
    for (int i = 0; i < n; i++) {
        if (cows[i].second == 0) {
            //cout << i << " " << r << endl;
            if (cows[i+1].second == 1) r = min(r, cows[i+1].first - cows[i].first);
            if (cows[i-1].second == 1) r = min(r, cows[i].first - cows[i-1].first);
        }
    }

    r--;

    if (id == 0) {cout << 0 << endl; return 0;} 
    sort(sick, sick+id);
    for (int i = 0; i < id - 1; i++) {
        if (sick[i + 1] - sick[i] > r) ans++;
    }

    cout << ans << endl;
}