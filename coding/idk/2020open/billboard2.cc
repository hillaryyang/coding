#include <iostream>
using namespace std;

struct bill{
    int x1, y1, x2, y2;
};

bill b, l;

int over(bill a, bill b) {
    int x = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
    int y = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));

    
    if ((x == b.x2 - b.x1 && (max(a.y1, b.y1) <= b.y1 || min(a.y2, b.y2) >= b.y2)) 
    || (y == b.y2 - b.y1)) return x * y;
    return 0;
}

int area(bill a) {
    return (a.x2 - a.x1) * (a.y2 - a.y1);
}

int main() {
    /*freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);*/

    cin >> l.x1 >> l.y1 >> l.x2 >> l.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    //cout << area(l) << endl;

    cout << area(l) - over(b, l) << endl;
}