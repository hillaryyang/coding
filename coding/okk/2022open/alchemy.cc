#include <iostream>
#include <vector>
using namespace std;

int n, k, q[101], to, qua, ans;
vector<int> r[101];

bool cook(int metal) {
    //case 1: we have an existing supply of metal
    //we subtract one from existing supply (q[metal]) 
    if (q[metal] > 0) {q[metal]--; return true;}

    //case 2: we have no existing supply and no recipe to make metal
    //we can't make it and we don't have it: return false
    if (r[metal].empty()) return false;

    //case 3: we have a recipe but no existing supply

    //we try cooking the components needed to make the metal
    for (auto ing : r[metal]) {
        //notice that recursion takes care of everything else
        if (!cook(ing)) return false;
    }
    return true;
}

int main() {
    cin >> n;

    //quantities are 1 indexed!!!
    for (int i = 0; i < n; i++) cin >> q[i + 1];
    cin >> k;
    while (k--) {
        //re is a temporary array to store the constitutents of a recipe
        vector<int> re;

        //"to" is what is made from the metals specified in re
        /*"qua" is the number of metals that must be combined to make "to"
        in other words, the size of re*/
        cin >> to >> qua;
        while (qua--) {
            //x is a component of the recipe
            int x; cin >> x;
            re.push_back(x);
        }
        /*r is the master list of all the recipe, so once 
        we're done inputting the information for the recipe 
        into "re", we put this into our array of vectors, r*/
        r[to] = re;
    }

    //while we can still cook to make n
    while (cook(n)) ans++;

    cout << ans << endl;
}