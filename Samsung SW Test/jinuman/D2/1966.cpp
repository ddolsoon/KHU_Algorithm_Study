// 숫자를 정렬하자

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    int n;
    for (int i = 0; i < T; ++i) {

        cin >> n;
        int arr[n];
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        sort(arr, arr + n);
        cout << '#' << i + 1 << ' ';
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << ' ';
        }
        cout << '\n';
    }
    return 0;
}