//https://www.acwing.com/problem/content/791/
#include <iostream>
using namespace std;

int n, q, a[100000]; 

int first (int x) {
    int l = 0, h = n - 1;
       while (l <= h) {
        int mid = l + (h - l)/2;
        if (x == a[mid] && (a[mid - 1] < x || mid == 0)) return mid;
        else if (x > a[mid]) l = mid + 1;
        else h = mid - 1;
    }
    
    return -1;
}

int last (int x) {
    int l = 0, h = n - 1;
    
    while (l <= h) {
        int mid = l + (h - l)/2;
        if (x == a[mid] && (a[mid + 1] > x || mid == n - 1)) return mid;
        else if (x < a[mid]) h = mid - 1;
        else l = mid + 1;
    }
    
    return -1;
}

int main() {
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    while (q--) {
        int x, s = -1, e = -1; cin >> x; 
        
        //cout << first(x) << endl;

        s = first(x); e = last(x);
        
        cout << s << " " << e << endl;
    }
}