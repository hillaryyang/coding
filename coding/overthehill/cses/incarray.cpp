#include <iostream>
using namespace std;

int main() {
long long n, mvct = 0; cin >> n;
long long a[n];

for (int i = 0; i < n; i++) cin >> a[i];

for (int i = 1; i < n; i++) {
    if (a[i] < a[i-1]) {
        mvct += a[i-1] - a[i];
        a[i] = a[i-1];
    }
}

cout << mvct << endl;

}