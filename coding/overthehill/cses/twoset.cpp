#include <iostream>
using namespace std;

int main() {
long n; cin >> n;
long a[n];
for (long i = 1; i <= n ; i++) a[i-1] = i;

long long toequal = n*(n+1)/2;

if (toequal % 2 == 1) cout << "NO" << endl;

else {
cout << "YES" << endl;
if (n % 4 == 0) {
long nums = n/2;
long spec = n/4;
cout << nums << endl;
for (long i = 0; i < spec; i++) cout << a[i] << " ";
for (long i = n - spec; i < n; i++) cout << a[i] << " ";
cout << endl;
cout << nums << endl;
for (long i = spec; i < n - spec; i++) cout << a[i] << " ";
cout << endl;
}

else if (n % 4 == 3) {
    long spec = (n + 1)/4;
    long nums;
    if (n != 3) nums = spec + 1;
    else nums = 1;
    long sum = 0;  

    cout << nums << endl;
    for (long i = n - spec; i < n; i++) sum += a[i];
    long other = toequal/2 - sum;
   
    if (other != 0) cout << other << " ";
    for (long i = n - spec; i < n; i++) cout << a[i] << " ";
    cout << endl;

    cout << n - nums << endl;
    for (long i = 0; i < n - spec; i++) {
        if (a[i] == other) continue;
        else cout << a[i] << " ";
    } cout << endl;
}
} 
}