// 간단한 369 게임

#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int i = 1;
    while (i <= n){
        int temp = i;
        bool check = false; // true이면 박수, false이면 숫자 출력
        // 문제에서 입력 값은 10~1000
        if ((temp >= 300 && temp < 400) || (temp >= 600 && temp < 700)
                || (temp >= 900 && temp < 1000)){
            cout << '-';
            check = true;
        }
        temp = temp % 100;
        if ((temp >= 30 && temp < 40) || (temp >= 60 && temp < 70)
            || (temp >= 90 && temp < 100)){
            cout << '-';
            check = true;
        }
        temp = temp % 10;
        if (temp == 3 || temp == 6 || temp == 9){
            cout << '-';
            check = true;
        }
        else if (!check){
            cout << i;
        }
        cout << ' ';
        i += 1;
    }
    return 0;
}