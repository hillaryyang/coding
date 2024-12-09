#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

int main() 
{
    map<string, int> a;
    a.insert({"a", {}});
    a["hillary"] = 2;

    a.find("hillary"); 
    
    return 0;
}