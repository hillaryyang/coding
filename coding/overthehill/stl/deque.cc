#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
/*Double Ended queue
can add/remove from both ends
slower than the rest though */

deque<int> a;
a.begin(), a.end(); 
a.front(), a.back();

a.push_back(1), a.push_front(2);
a[0]; 

a.pop_back(), a.pop_front();

a.clear();
}
