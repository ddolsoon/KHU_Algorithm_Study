// SW Test 3th days.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

int arr[10];

int main()
{
	int t;
	string s;
	int num = 1;
	cin >> t;
	while (t--) {

		
		cin >> s;
		bool palindrome = true;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - i - 1]) {
				palindrome = false;
			}
		}

		if (palindrome) {
			cout << '#' << num++ << ' ' << 1 << '\n';
		}
		else {
			cout << '#' << num++ << ' ' << 0 << '\n';
		}

		
	}
	
    return 0;
}

