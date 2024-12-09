#include <iostream>
using namespace std;

int paths (int n, int m) {
    if (n == 1 || m == 1) return 1;
    else return paths (n, m-1) + paths (n-1, m);
}

int main() {
    cout << paths(4, 5) << endl;
}