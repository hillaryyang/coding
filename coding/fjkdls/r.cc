#include <iostream>
#include <vector>
using namespace std;

vector<int> loc[100];
int ct;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s; cin >> s;
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == (char) ('A' + i)) loc[i].push_back(j);
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i != j && loc[i][0] < loc[j][0]
            && loc[i][1] < loc[j][1] 
            && loc[j][0] < loc[i][1]) ct++;

            /*if (loc[j][0] < loc[i][0]
            && loc[j][1] > loc[i][1] 
            && loc[i][0] < loc[j][1]) ct++;*/
        }
    }

    cout << ct << endl;
}