#include <iostream>
#include <vector>
#include <tuple>
#include <queue> 
#include <algorithm>
#define pb push_back
#define mt make_tuple
#define ll long long
#define f first
#define s second
using namespace std;

int main() {
    ll x, y, n, mx = 0;
    //storing arrival time, seniority, time spent eating
    vector<tuple<ll, ll, ll> > a;
    priority_queue<tuple<ll, ll, ll> > wait;
    
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y; a.pb(mt(x, i, y));
    }

    sort(a.begin(), a.end());

    //for (auto i : a) cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    ll nex = 1, st = get<0>(a[0]), t = get<2>(a[0]);
    while (nex <= n) {
        //find the cows to be added to the waitlist
        //cout << "next cow: " << nex << endl;
        for (int i = nex; i < n; i++) {
            if (get<0>(a[i]) <= st + t) {
                //cout << -1 * get<1>(a[i]) << " " << get<0>(a[i]) << " " << get<2>(a[i]) << endl;
                wait.push(mt(-1 * get<1>(a[i]), get<0>(a[i]), get<2>(a[i]))); nex++;
            }
            else break;
        }

        //current cow finishes eating
        if (wait.empty()) {
            st = get<0>(a[nex]), t = get<2>(a[nex]);
            nex++;
        }

        else {
            //check how long next cow has been waiting for
            ll finish = st + t;
            //cout << finish << " " << get<1>(wait.top()) << endl;
            mx = max(mx, finish - get<1>(wait.top()));
            st = finish, t = get<2>(wait.top());
            //cout << st << " " << t << endl;
            wait.pop();
        }
    }

    cout << mx << endl;
}