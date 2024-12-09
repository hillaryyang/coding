#include <iostream>
#include <stack>

using namespace std;

int main() {
//use a stack! only add and remove from the top
/*
stack:
|   |
| _ |
| _ |
| _ |
| _ |
*/

stack<int> stk;
stk.push(1); //adds to the top of the stack
stk.top(); //top of the stack
stk.pop(); //takes off the top 

}
