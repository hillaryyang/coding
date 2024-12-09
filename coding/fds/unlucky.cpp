#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int N = 20000 + 10;
vector<string> ind[10];

/**
  * NOTE: This template reads in values as int. You may want to change this for
  * bonus test sets.
  * 
  * Find the largest D digit number that does not contain any unlucky number
  * from L.
  *
  * N: the number of unlucky numbers
  * D: the number of digits in the number to find
  * L: the list of unlucky numbers
  */

bool check(string s) {
    char c = s[s.length() - 1];
    for (string un : ind[c - '0']) {
        int x = un.length();
        if (x > s.length()) continue;
        if (s.substr(s.length() - x, x) == un) return false;
    }

    return true;
}

string solve(int n, int d, vector<string> &L) {
    string res = "";
    for (int i = 0; i < d; i++) {
        for (int j = 9; j >= 1; j--) {
            if (check(res + to_string(j))) {
                res += to_string(j);
                break;
            }
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        for (int i = 0; i < 10; i++) {
            ind[i].clear();
        }
        int N, D;
        cin >> N >> D;
        vector<string> L(N);
        for (string &L_i : L) {
            cin >> L_i;
            ind[L_i[L_i.size() - 1] - '0'].push_back(L_i);
        }   
        cout << solve(N, D, L) << "\n";
    }
}
