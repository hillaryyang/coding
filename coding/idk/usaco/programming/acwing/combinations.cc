#include <iostream>
#include <cmath>
using namespace std;

int choose(int n, int r) {
if (r == 0) return 1; //if r is zero then there's one way to choose
if (r > n / 2) return choose (n, n-r); //if r is greater than half of n
//then it's more efficient to compute n choose n-r, which is the same
long res = 1;
for (int k = 1; k <= r; k++) { //loops thru r times
    res *= n - k + 1; //n! and (n-k)! cancel out to be (n-k+1)!
    res /= k; //divide by k!
}
return res;
}


int main() {
int m, n; cin >> m >> n;
cout << choose(m+n, n) << endl;
}