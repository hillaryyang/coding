#include <iostream>
using namespace std;

class Solution {
public: 
    int sum(int n) {
        int res = n;
        (n > 0) && (res += sum(n-1));
        return res;
    }
};

int main() {
int n; cin >> n;
Solution mySol;
cout << mySol.sum(n) << endl;
}