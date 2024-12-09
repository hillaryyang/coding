#include <iostream>
using namespace std;

class Person {
    private:
        int age, height;
        double money;
        string books[100];

    public:
        string name;
        void say() {
            cout << "I'm " << name << endl;
        }
        int getage() {
            return age;
        }
        void addmoney(double x) {
            money += x;
        }
};

int main() {
    Person c;
    
    c.name = "Hillary!";
    //c.age = 14;
    cout << c.getage() << endl;
    c.addmoney(1);

    return 0;
}