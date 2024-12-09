#include <iostream>
using namespace std;

//iterative approach
int itsearch(int arr[], int x, int l, int r) {
    while (l != r) {
        int mid = (l+r)/2;
        if (x==arr[mid]) return mid;
        else if (x > arr[mid]) l = mid+1;
        else r = mid-1;
    }
    return l;
}

//recursive approach
int research(int arr[], int x, int l, int r) {
    if (l > r) return 0;
    else {
        int mid = (l+r)/2;
        if (x==arr[mid]) return mid;
        else if (x > mid) return research(arr, x, mid+1, r);
        else return research(arr, x, l, mid-1);
    }
}

int main() {
int b; 
cout << "What is the size of the array? "; cin >> b;
int a[b]; 

cout << "Enter the elements of the array: ";
for (int i = 0; i < b; i++) cin >> a[i];

int x; cout << "What do you want to find: "; cin >> x;

cout << x << " is at the " << research(a, x, a[0], a[b-1]) + 1 << "th position." << endl;


}