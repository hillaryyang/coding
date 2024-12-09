#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> str, edit;

bool comp(string a, string b) {
    return a < b;
}

bool compare(string a, string b) {
    int x = a.length(), y = b.length();
    if (x > y) return 1;
    if (x < y) return 0;

    else return comp(a, b);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {string s; cin >> s; str.push_back(s);}

    for (auto c : str) {
        //analyze c
        string o, t;
        for (auto cha : c) if (cha != 'x') o += cha;

        int yct = 0;
        for (auto cha : o) {
            if (cha == 'y') yct++;
            else t += cha;
        }

        while (yct--) t += 'y';

        edit.push_back(t);
    }

    sort(edit.begin(), edit.end(), compare);

    for (auto c : edit) cout << c << endl;
}