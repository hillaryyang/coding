#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string a;
int n, m, t, r;
vector<vector<int> > b;
vector<int> res(m);

void remove_rows(int pos, int val) {
    vector<int> tmp_res;
    vector<vector<int> > tmp_b;
    for (int i = 0; i < b.size(); i++) {
        if (b[i][pos] != val) {
            tmp_b.push_back(b[i]);
            tmp_res.push_back(res[i]);
        }
    }
    b = tmp_b;
    res = tmp_res;
}

int main() {
    cin >> t;
    while (t--) {
        b.clear();
        res.clear();
        cin >> n >> m;
        b.resize(m);
        for (int i = 0; i < m; i++) {
            b[i] = vector<int>(n);
            cin >> a >> r;
            res.push_back(r);
            for (int j = 0; j < n; j++) {
                b[i][j] = a[j] - '0'; 
            }
        }
        bool flag = true;
        while (flag) {
            bool consistent = false;

            for (int i = 0; i < n; i++) {
                int c0 = 0, s0 = 0, c1 = 0, s1 = 0;
                for (int j = 0; j < b.size(); j++) {
                    if (b[j][i] == 0) {c0++; s0 += res[j];}
                    else if (b[j][i] == 1) { c1++; s1 += res[j];}
                }

                if ((c0 > 0 && s0 == 0) || (s0 != 0 && s0 == c0)) {
                    consistent = true;
                    remove_rows(i, 0);
                    break;
                }

                else if ((s1 != 0 && s1 == c1) || (s1 == 0 && c1 > 0)) {
                    consistent = true;
                    remove_rows(i, 1);
                    break;
                }
            }

            if (!consistent) {
                if (b.empty()) cout << "OK" << endl; 
                else cout << "LIE" << endl;
                flag = false;
            }
        }
    }
}