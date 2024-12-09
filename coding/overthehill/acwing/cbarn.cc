#include <iostream>
using namespace std;

int n, dist;
int mindist = 100000000; 

int main() {

    freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

    cin >> n;
    int cows[n];
    
    for (int i = 0; i < n; i++) cin >> cows[i];
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                dist += cows[j] * (j - i);
             }

            else if (i > j) {
                dist += cows[j] * (n-i+j);
            }
        } 
    if (dist < mindist) mindist = dist;
    dist = 0;
    }
    cout << mindist << endl;
}