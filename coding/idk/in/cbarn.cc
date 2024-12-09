#include <iostream>
#include <vector>
using namespace std;

vector<int> r;
int small = 100000000;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        r.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        //i is the door that they go in from
        int cur = 0;
        for (int j = i; j < i + n; j++) {
            int a = (j - i) * r[j % n];
            cur += a;
        }

        if (cur < small) small = cur;
    }

    cout << small << endl;
}