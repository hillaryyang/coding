#include <iostream>
using namespace std;

int b[1010];

int ct(int a[], int n) {
int unique = 0; 
for (int i = 0; i < n; i++) b[a[i]]++;

for (int i = 0; i < 1010; i++) {
    if (b[i]) unique++;
}
return unique;
}

int main() {
int n; cin >> n;
int a[n];
for (int i = 0; i < n; i++) cin >> a[i];
cout << ct(a, n) << endl;
}