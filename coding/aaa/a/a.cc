#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct intpt {
    int c1, c2, t1, t2;

    bool operator < (const intpt &other) const {
        if (t2 == other.t2) {
            //int points at same time are simultaneously processed
            if (c1 == other.c1) {
                if (c2 == other.c2) return t1 < other.t1;
            }
            return c1 < other.c1;
        }
        //sorted by time 2
        return t2 < other.t2;
    }
};

int main() {
    int n, a, b; cin >> n;
    vector <char> dir (n); 
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) cin >> dir[i] >> x[i] >> y[i];
        
    vector<intpt> intersect;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dir[i] != dir[j]) {
                //one facing E, one facing N
                a = i, b = j; 
                if (dir[a] == 'N') swap(a, b);
                //guarantees that cow a faces E, cow b faces N
                if (x[b] > x[a] && y[a] > y[b]) {
                    int timeA = x[b] - x[a], timeB = y[a] - y[b];
                    if (timeA > timeB) intersect.push_back({b, a, timeB, timeA});
                    else if (timeB > timeA) intersect.push_back({a, b, timeA, timeB});
                    //if timea = timeb, the cows just keep going
                }
            }
        }
    }

    sort(intersect.begin(), intersect.end());


}