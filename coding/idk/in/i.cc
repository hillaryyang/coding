#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> scroll, ne;

bool compare(string &s1,string &s2)
{
    if (s1.size() > s2.size()) return true;
    if (s1.size() < s2.size()) return false;
    
    return s1[0] < s2[0];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {string s; cin >> s; scroll.push_back(s);}
    
    for (auto c : scroll) {
        string cur = "";
        for (int i = 0; i < (int) c.length(); i++) {
            if (c[i] != 'x') cur += c[i];
        }

        int yct = 0;
        string real = "";

        for (auto h : cur) {
            if (h == 'y') yct++;
            else real.push_back(h);
        }

        for (int i = 0; i < yct; i++) real += 'y';

        ne.push_back(real);
    }
    
    sort(ne.begin(), ne.end(), compare);
    
    for (auto c : ne) cout << c << endl;
    
    return 0;
}