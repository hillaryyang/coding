#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll n, t, x, y, total, remaining, last_day;
vector <pair<int, int> > d;

int main() {
    cin >> n >> t;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        d.push_back(make_pair(x, y));
    }
    
    for (int i = 0; i < n; i++) {
        //d[i].first is the day of the delivery
        //d[i].second is the number of bales that were delivered
        
        //we add the number of bales in delivery to total amount 
        total += d[i].second;
        
        /*a total of d[i].first - last_day bales were consumed
        in between the deliveries*/
        
        remaining -= d[i].first - last_day;
        
        //set the last_day to the current day (the "new" last_day)
        last_day = d[i].first;
        
        /* accounts for the addition of the bales in the newest delivery
        to remaining; we also have to check if Bessie ate all the bales 
        (taking the max of 0 and remaining) and then add the bales delivered
        */
        remaining = max((ll)0, remaining) + d[i].second;
    }
    
    cout << total - remaining << endl;
}