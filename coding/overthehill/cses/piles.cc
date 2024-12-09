#include <iostream>
using namespace std;
#define ll long long

int main() {
int t; cin >> t;
while (t--) {
int a, b; cin >> a >> b;

if (a < b) swap(a, b); //a is the bigger one

if (a > 2 * b) cout << "NO" << endl;
else if ((a+b) % 3 == 0) cout << "YES" << endl;
else cout << "NO" << endl;
}
}