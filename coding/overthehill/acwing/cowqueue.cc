#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);

    int n, curr=0;
    cin >> n;
    
    vector<pair<int, int> > cows(n); 
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    for (int i = 0; i < n; i++) {
        //if the cow has already been waiting in the queue, which happens 
        //when the current time is greater than the time that the cow joined
        //the queue then we just have to add the time that it takes to be questioned
        if (curr > cows[i].first) curr += cows[i].second;
        else curr = cows[i].first + cows[i].second;
    }

    cout << curr << endl;
}

