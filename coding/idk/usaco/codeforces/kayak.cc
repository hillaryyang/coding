//https://codeforces.com/problemset/problem/863/B
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<int> w;
int n, x, mn = 1000000000;

int main() {
    cin >> n;
    int p = 2 * n;

    for (int i = 0; i < p; i++) {cin >> x; w.push_back(x);}

    sort(w.begin(), w.end());

    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            int cur = 0;
            //w[i] and w[j] are the singles

            vector<int> temp;
            for (int k = 0; k < p; k++) {
                if (k != i && k != j) temp.push_back(w[k]);
            }

            for (int k = 0; k < temp.size(); k += 2) {
                cur += (temp[k + 1] - temp[k]);
            }

            mn = min(mn, cur);

            temp.clear();
        }
    }

    cout << mn << endl;
}