#include <iostream>
using namespace std;

int main() {
long long n; 
cin >> n;
long long sub = 0; 

for (long long i = 1; i <= n; i++) {
    if (n == 1) cout << 0 << endl;
    else {
        long long choose = (i*i)*(i*i-1)/2;
        cout << choose - sub << endl;
        sub += 8 * (i-1);
        }
    }
}
