// 패턴 마디의 길이

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    string str = "";
    for (int i = 0; i < T; ++i) {
        cin >> str;
        reverse(str.begin(), str.end());    // 문자열 뒤집기
        cout << '#' << i + 1 << ' ';
        for (int j = 1; j < str.size(); ++j) {
            if(str[0] == str[j]){
                cout << j;
                break;
            }
        }
        cout << '\n';
    }
    return 0;
}