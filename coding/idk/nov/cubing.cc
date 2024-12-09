//https://codeforces.com/problemset/gymProblem/102500/E
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
const int N = 1010;
using namespace std;

int main() {
    float x, t, epsilon = 0.001; vector<float> a;
    for (int i = 0; i < 4; i++) {cin >> x; a.pb(x);}
    cin >> t;

    sort(a.begin(), a.end());

    //for (float i : a) cout << i << " "; cout << endl;
    //cout << (a[0] + a[1])/2 << endl;

    if (fabs((a[1] + a[2] + a[3])/3) - t <= epsilon) cout << "infinite" << endl;
    else if (fabs((a[0] + a[1] + a[2])/3) - t > epsilon) cout << "impossible" << endl;
    else {
        cout << fixed << setprecision(2) << 3 * t - a[1] - a[2] << endl;
    }
}