#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
queue <int> q;

//for queue
q.push(1); //adds 1 to the back of the queue
q.pop(); //takes one off from the front
q.front(); //returns the first element
q.back(); //gives last element
//FIFO

priority_queue<int> a; //max heap
priority_queue<int, vector<int>, greater<int>> b; //min heap
priority_queue<pair<int, int>> c; 

//for priority queue
a.push(1); //add one element but don't know where it goes
a.top(); //gets the top value
a.pop(); //gets rid of the top value

//push adds from the back, pop removes from the front

}