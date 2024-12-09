/*
ID: hillary3
TASK: milk3
LANG: C++                 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct state {
    int a[3];
};

int seen[21][21][21], ok[21];

state st(int a, int b, int c) {
    state s;
    s.a[0] = a; s.a[1] = b; s.a[2] = c;
    return s;
}

int cap[3];

state pour(state s, int from, int to) {
    int amt;

    amt = s.a[from];
    if (s.a[to] + amt > cap[to]) amt = cap[to] - s.a[to];

    s.a[from] -= amt;
    s.a[to] += amt;

    return s;
}

void search (state s) {
    int i, j;

    if (seen[s.a[0]][s.a[1]][s.a[2]]) return;

    seen[s.a[0]][s.a[1]][s.a[2]] = 1;

    if (s.a[0] == 0) ok[s.a[2]] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) search(pour(s, i, j));
    }
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    cin >> cap[0] >> cap[1] >> cap[2];

    search(st(0, 0, cap[2]));

    for (int i = 0; i <= cap[2]; i++) {
        if (ok[i]) {
            cout << i;
            if (i != cap[2]) cout << " ";
        }
    } cout << endl;
}   


