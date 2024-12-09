#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve (int N, vector<int> c) {
int wait = 0;
int size = c.size();
int places[size+1];

for (int i = 1; i <= size; i++) places[i] = c[i-1];

sort(c.begin(), c.end());

for (int i = 1; i < size+1; i++) {
    wait += c[i-1] * (size+1-i);
} cout << wait << endl;

for (int i = 0; i < size; i++) {
    for (int j = 1; j <= size; j++) {
        if (c[i] == places[j]) cout << j << " ";
    }
}
cout << endl;
}

int main () {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        vector<int> C(N);
        for (int &C_i: C) cin >> C_i;
        solve(N, C);
    }
}