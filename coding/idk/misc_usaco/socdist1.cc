//http://www.usaco.org/index.php?page=viewproblem2&cpid=1035
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;

const int N = 1e5 + 10;

int main() {
    /*freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);*/

    int n, max1, max2; string s;
    cin >> n >> s;

    vector<int> gaps, pos, temp;

    int ct = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ct++;
            if (i < n - 1 && s[i + 1] == '1') {gaps.pb(ct); ct = 0;}
        }
    } if (ct != 0) gaps.pb(ct);
    
    for (int i : gaps) temp.pb(i);
    for (int i : gaps) cout << i << " "; cout << endl;

    if (gaps.size() == 1 && s[0] == '0' && s.back() == '0') {cout << n - 1 << endl; return 0;}

    //calculating the max distance if the two cows go into different slots
    if (temp.size() > 1) {
        if (s[0] == '0') {pos.pb(temp[0]); temp.erase(temp.begin());}
        if (s.back() == '0') {pos.pb(temp.back()); temp.pop_back();}
        //for (int i : pos) cout << i << " "; cout << endl;
        for (int i = 0; i < temp.size(); i++) {
            //cout << i << " " << ceil((double)i/2) << endl;
            pos.pb(ceil((double)(temp[i])/2));
        }

        sort(pos.begin(), pos.end(), greater<int>());

        //for (int i : pos) cout << i << " "; cout << endl;

        max1 = pos[1];
    }

    pos.clear();
    
    //calculate max distance if they go into the same slot
    if (s[0] == '0') pos.pb(floor((double)gaps[0]/2)); 
    if (s.back() == '0') pos.pb(floor((double)(gaps.back())/2)); 
    //for (int i : gaps) cout << i << " "; cout << endl;

    for (int i = 0; i < gaps.size(); i++) {
        //cout << i << " " << round((double)i/3) << endl;
        if ((i == 0 && s[0] =='0') || (i == gaps.size() - 1 && s.back() == '0')) continue;
        pos.pb(round((double)gaps[i]/3));
    }

    sort(pos.begin(), pos.end(), greater<int>());
    //for (int i : pos) cout << i << " "; cout << endl;

    max2 = pos[0];
    cout << max1 << " " << max2 << endl;

    cout << max(max1, max2) << endl;
}