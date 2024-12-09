//https://codeforces.com/contest/1804/problem/B
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int t, n, k, d, w, x;
vector<int> ti;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k >> d >> w;
        for (int i = 0; i < n; i++) {cin >> x; ti.push_back(x);}

        //at moment ti[0], open up a new pack
        int doses_left = k - 1, ct = 1, time_opened = ti[0] + w;

        for (int i = 1; i < n; i++) {
            //cout << i << " " << doses_left << endl;
            if (doses_left > 0 && ti[i] - time_opened <= d) {doses_left--; continue;}

            else {
                //open a new pack
                ct++; doses_left = k - 1; time_opened = ti[i] + w;
            }
        }

        ti.clear();

        cout << ct << endl;
    }
}