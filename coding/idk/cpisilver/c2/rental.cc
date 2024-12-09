//http://www.usaco.org/index.php?page=viewproblem2&cpid=787
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

vector<ll> c, rent;
vector<pair<ll, ll> > store;

bool comp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

int main() {
    ll N, M, R, x, q, p, r, ans = 0; cin >> N >> M >> R;

    //input cows
    for (int i = 0; i < N; i++) {
        cin >> x; c.pb(x);
    }

    //input buying offers
    for (int i = 0; i < M; i++) {
        cin >> q >> p; store.pb(mp(q, p));
    }

    //input rental offers
    for (int i = 0; i < R; i++) {cin >> r; rent.pb(r);}

    //sort rental offers in decreasing price
    sort(rent.begin(), rent.end());
    //sort buying offers
    sort(store.begin(), store.end(), comp);
    //sort cows
    sort(c.begin(), c.end());

    /*for (int i : c) cout << i << " "; cout << endl;
    for (auto i : store) cout << i.first << " " << i.second << endl;
    for (int i : rent) cout << i << " "; cout << endl;*/

    while (!c.empty()) {
        //renting worst cow
        ll a = rent.back(), b = 0; vector<pair<ll, ll> > temp;

        //selling best cow milk
        //we have c.back() gallons to sell 
        for (auto i : store) temp.pb(i);
        //for (auto i : temp) cout << i.first << " " << i.second << "; "; cout << endl;
        ll cur = temp.size() - 1, val = c.back();
        while (val > 0) {
            if (temp[cur].first >= val) {temp[cur].first -= val; b += val * temp[cur].second; val = 0; break;}
            else {
                val -= temp[cur].first; temp[cur].first = 0; b += val * temp[cur].second;
            }

            if (temp[cur].first == 0) temp.pop_back();
            cur--;
        }

        //for (auto i : temp) cout << i.first << " " << i.second << "; "; cout << endl;

        //cout << a << " "<< b << endl;

        if (a >= b) {
            //we rent the worst cow
            ans += a;
            rent.pop_back(); c.erase(c.begin());
        }

        else {
            //we sell milk
            ans += b;
            store.clear();
            for (auto i : temp) store.pb(i);
            c.pop_back();
        }
 
        /*for (auto i : store) cout << i.first << " " << i.second << "; "; cout << endl;
        cout << "cows: "; for (int i : c) cout << i << " "; cout <<endl;
        cout << ans << endl;

        cout << endl;*/
    }

    cout << ans << endl;
}