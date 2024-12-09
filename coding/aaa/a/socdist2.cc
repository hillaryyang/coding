#include <iostream>
using namespace std;

int n, x, s, ct, state, start, ans, loc[1000001];

int main() {
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> s;
        if (s == 1) loc[x] = 1;
        else if (s == 0) loc[x] = -1;
    }

    //smallest distance between -1 and 1
    int small = 1000001, cur = -1;
    for (int i = 0; i < 1000000; i++) {
        if (loc[i] != 0) { //if there's actually a cow there
            if (cur != -1 && loc[cur] != loc[i] && i-cur<small) small = i-cur;
            cur = i; //changes so that the comparison is between the last slot with a cow
            //and the ith cow
        }
    }

    for (int i = 0; i < 1000000; i++) {
        if (loc[i] != 0) {
            if (loc[i] != state && loc[i] == 1) ct++;
            //if we change from healthy to sick, we get a new block
            state = loc[i];
        }
    } 

    for (int i = 0; i < 1000000; i++) {
        //checks every cow with the occupied one after it?
        if (loc[i] != 0) {
            if (start != 0 && loc[start] == 1 && loc[i] == 1 && i-start >= small) ans++;
            start = i;
        }
    }

    cout << ans + ct << endl;

}