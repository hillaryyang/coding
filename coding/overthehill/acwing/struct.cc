#include <iostream>
using namespace std;

struct Person {
    int age, height;
    double money;

    Person(int _age, int _height, double _money) {
        age = _age;
        height = _height;
        money = _money;
    }
};

int main() {
    Person p(14, 180, 100.0);
 
    return 0;
}