#include <iostream>
using namespace std;

int partitions(int n, int m) {
    if (n == 0) return 1;
    else if (m == 0 || n < 0) return 0; 

    else return partitions(n-m, m) + partitions(n, m-1);
}

int main() {

}