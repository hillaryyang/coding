#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

/**
 * Return the best number to "zero out" in order to
 * minimize the expected value of a dice roll.
 * 
 * N: the number of faces on the die
 * X: the list of numbers on each face of the die
 */

int num_appear (int n, vector<int> X) {
    int ct = 0;
    for (auto c : X) if (c == n) ct++;

    return ct;
}

int solve(int N, vector<int> X) {
    int mx = 0, ans;

    for (auto c : X) if (num_appear(c, X) * c > mx) mx = num_appear(c, X) * c;

    //cout << mx << endl;

    for (auto c : X) if (num_appear(c, X) * c == mx) ans = c;

    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> X(N);
        for (int &item : X) {
            cin >> item;
        }
        cout << solve(N, X) << endl;
    }
}
