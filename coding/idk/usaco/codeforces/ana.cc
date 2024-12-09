#include <iostream>
#include <string>
using namespace std;

string s, a;

int main() {
    freopen("anagrams.in", "r", stdin);
    freopen("anagrams.out", "w", stdout);

    vector<string> str;
    while (cin >> s) {
        sort(s.begin(), s.end());
        str.push_back(s);
    }

    sort(str.begin(), str.end());
    for (string s : str) cout << s << endl;
}