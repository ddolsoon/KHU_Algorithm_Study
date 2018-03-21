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
                if (str[j-1] == str[j]) {
                    /**
                     * 만약 같은 문자가 연속된다면 예외처리 해줌
                     */
                    for (int k = 0; k < str.size(); ++k) {
                        if (str[0] != str[k]) {
                            cout << k * 2 + 1 <<'\n';
                            break;
                        }
                    }
                    break;
                } else {
                    cout << j << '\n';
                    break;
                }

            }
        }
    }
    return 0;
}