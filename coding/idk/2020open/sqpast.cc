#include <iostream>
using namespace std;

struct sq{
    int x1, y1, x2, y2;
};

int main() {
    sq a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    int x1 = min(a.x1, b.x1), x2 = max(a.x2, b.x2);
    int y1 = min(a.y1, b.y1), y2 = max(a.y2, b.y2);

    //cout << x1 << " " << x2 << " "<< y1 << " " << y2 << endl;

    int len = max(x2-x1, y2-y1);
    cout << len*len << endl;
}