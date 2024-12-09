#include <iostream>
using namespace std;

class sol {
public:
    int fib(int n) {
    if (n <= 1) return n;
    else return fib(n-2) + fib(n-1);
    }
};
 
int main() {
    int n; cin >> n;
    sol mysol;
    cout << mysol.fib(n) << endl;
}