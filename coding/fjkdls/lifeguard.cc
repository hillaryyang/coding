#include <iostream>
#include <vector>
using namespace std;

int n, t[1000], temp[1000], mx;
vector<pair<int, int> > c;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e; 
        cin >> s >> e;
        c.push_back(make_pair(s, e));
    }

    for (int i = 0; i < n; i++) {
        for (int j = c[i].first; j < c[i].second; j++) t[j]++;
    }

    for (int i = 0; i < n; i++) {
        int cur = 0;
        //reset temp
        for (int j = 0; j < 1000; j++) temp[j] = t[j];

        for (int j = c[i].first; j < c[i].second; j++) temp[j]--;

        for (int j = 0; j < 1000; j++) if (temp[j] != 0) cur++;

        mx = max(mx, cur);
    }

    cout << mx << endl;
}