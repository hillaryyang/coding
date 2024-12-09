#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() 
{
    int x;
    set<int> a; //no duplicates
    multiset<int> b; //can duplicate

    set<int>::iterator it = a.begin();
    it++; it--;
    ++ it; -- it;
    a.end();
    
    a.insert(x);
    a.find(x); //finds x

    a.lower_bound(x); //iterator pointing to greater than or equal x
    a.upper_bound(x); //GREATER than x 

    a.erase(it);

    a.count(x); //0 if doesn't appear, 1 if appears
    //just regular count in a multiset

    struct Rec
    {
        int x, y;
        bool operator < (const Rec& t) const {
            return x < t.x;
        }
    };

    set<Rec> c;

}