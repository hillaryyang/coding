#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long ans, n, heights[21], stalls[21], fits[21];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> heights[i];
    
    for (int i = 0; i < n; i++) cin >> stalls[i];

    sort(heights, heights + n, greater<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (heights[i] <= stalls[j]) fits[i]++;
        }
    }

    ans = 1;

    for (int i = 0; i < n; i++) {
        long long x = fits[i] - i;
        ans *= x; 
    }

    cout << ans << endl;
}