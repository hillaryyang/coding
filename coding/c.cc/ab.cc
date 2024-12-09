/*
ID: hillary3
TASK: pprime
LANG: C++
*/

# include <iostream>
# include <cmath>
# include <string.h>
using namespace std;
bool book[10000001]; // 用埃氏筛法生成质数表
void isprime(int b) {
    memset(book, true, sizeof(book)); // 初始化列表，默认全部都是质数
    book[1] = false; // 1不是质数
    for (int i = 2;i <= sqrt(b);i ++) {
        if (book[i]) {
            //质数的倍数绝对不是质数，把所有质数的倍数全部设为false
            for (int j = 2;j <= b / i;j ++)
                book[i * j] = false;  // 因为i * j <= b
        }
    }
}
//判断回文数
bool isHWS(int num) {
    int temp = num,ans = 0;
    while (temp != 0) {
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    if (ans==num) return true;
    else return false;
}

int main() {
    int a,b;
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    scanf("%d %d",&a,&b);
    if (b >= 10000000) b = 9999999;
    isprime(b);
    if(a > b) return 0;
    if (a % 2 == 0) a ++; // 2的倍数不可能是质数（除2以外）
    for (int i = a;i <= b;i += 2) {
        if (book[i] && isHWS(i)) printf("%d\n",i);//如果既是质数并且也是回文数，就输出
    }
    return 0;
}