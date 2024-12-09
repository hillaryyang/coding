#include <iostream>
using namespace std;

/*int main() {
    int a = 10;
    int *p = &a; 
    int **q = &p; //pointers to pointers
    int ***o = &q;

    cout << *p << endl;
    *p = 12;

    cout << *p << endl;
    cout << a << endl;

    return 0;
}

int main() {
    int a = 10;

    int *p = &a;
    int &p = a;

}*/

struct Node 
{
    int val;
    Node* next;
    Node(int _val) : val(_val), next(NULL) {}
};

int main() {
    
    Node* p = new Node(1);
    Node* q = new Node(2); 
    Node* o = new Node(3);

    p->next = q;
    q->next = o;

    Node* head = p;

    for (Node* i = head; i; i = i->next)
        cout << i->val << endl;
}