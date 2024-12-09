#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    //int a[] = {1, 1, 2, 2, 3, 3, 4};
    vector<int> a;

    srand(time(0));

    /*int m = unique(a.begin(), a.end()) - a.begin();
    cout << m << endl;
    for (int i = 0; i < m; i++) cout << a[i] << " ";
    cout << endl;*/

    //shuffle(a.begin(), a.end());

    //sort(a.begin(), a.end());
    //sort(a.begin(), a.end(), greater<int>()); //big to small

    for (int x : a) cout << x << " ";
    cout << endl;
    sort(a.begin(), a.end(), cmp);
}