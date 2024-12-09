#include <iostream>
using namespace std;

struct bill{
    int x1;
    int y1;
    int x2;
    int y2;
};

int over(bill a, bill b) {
    int x = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
    int y = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
    return x * y;
}

int area(bill a) {
    return (a.x2 - a.x1) * (a.y2 - a.y1);
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    bill b1, b2, t;

    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2 >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    int tot = area(b1) + area(b2) - over(b1, t) - over(b2, t);

    cout << tot << endl;
}