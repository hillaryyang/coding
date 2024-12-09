//https://codeforces.com/contest/1826/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, ans = -1; cin >> n;
        vector<int> nums;
        
        for (int i = 0; i < n; i++) {int x; cin >> x; nums.push_back(x);}

        sort(nums.begin(), nums.end());

        for (int i = nums[0]; i <= nums[n - 1]; i++) {
            //there are at least i liars
            int liars = 0;

            for (int j = 0; j < n; j++) {
                if (nums[j] > i) liars++;
            }

            if (liars == i) ans = liars;
        }

        nums.clear();

        cout << ans << endl;
    }
}