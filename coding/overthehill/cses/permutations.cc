#include <iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    if (n == 1) cout << 1 << endl;
    else if (n < 4) cout << "NO SOLUTION" << endl;
    else if (n % 2 == 0) { //if n is even
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) cout << i << " ";
        }
        for (int i = 1; i <= n/2; i++) {
            cout << 2*i-1 << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) cout << i << " ";
        }
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) cout << i << " ";
        }
        cout << endl;
    }
}