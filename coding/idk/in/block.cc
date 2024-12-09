#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

vector< pair<string, string> > blocks;
int ans[26];

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string x, y; cin >> x >> y;
        blocks.push_back(make_pair(x, y));
    }

    for(int i = 0; i < n; i++) {
        int c1[26], c2[26];
        memset(c1, 0, sizeof(c1)); memset(c2, 0, sizeof(c2));

        for (auto c : blocks[i].first) c1[c - 'a']++;
        for (auto c : blocks[i].second) c2[c - 'a']++;

        for (int i = 0; i < 26; i++) ans[i] += max(c1[i], c2[i]);
    }

    for (auto c : ans) cout << c << endl;
}