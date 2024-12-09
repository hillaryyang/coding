#include <iostream>
using namespace std;

int main() {
long t; cin >> t;

while (t--) {
long long x, y; cin >> y >> x;
long long a;
if (x == y) {
cout << x + (x-1) * (x-1) << endl;
}

else {
long long sq = max(x, y);
if (sq == x) {
if (x % 2 == 1) {
    a = x*x;
    cout << a - y + 1 << endl;
}
else {
    a = (x-1)*(x-1)+1; 
    cout << a + y - 1 << endl;
}

}
else {
if (y % 2 == 0) {
    a = y*y;
    cout << a - x + 1 << endl;
}

else {
    a = (y-1) * (y-1) + 1;
    cout << a + x - 1 << endl;
}
}

}
}
}