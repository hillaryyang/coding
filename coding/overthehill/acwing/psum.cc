#include <iostream>
using namespace std;

void psum(int arr[], int n, int prefixsum[]) {
    prefixsum[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefixsum[i]=prefixsum[i-1]+arr[i];
}

int main() {
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int prefixsum[7];
    psum(arr, 7, prefixsum);
    for (int i = 0; i < 7; i++) cout << prefixsum[i] << " ";
    cout << endl;
}