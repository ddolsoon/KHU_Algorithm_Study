// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

int ans;

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

void backtracking(string s, int n, int k) {

	if (n == k) {
		if (ans < stoi(s)) {
			ans = stoi(s);
		}
		return;
	}

	for (int i = 0; i < s.length() - 1; i++) {
		for (int j = i + 1; j < s.length(); j++) {

			swap(s[i], s[j]);
			backtracking(s, n + 1, k);
			swap(s[i], s[j]);
		}
	}

}

int main()
{
	int t;
	int num = 1;
	cin >> t;
	while (t--) {

		string s;
		int k;

		cin >> s;
		cin >> k;

		if (k >= 6) {
			if (k % 2 == 0) {
				k = 4;
			}
			else {
				k = 5;
			}
		}
		ans = 0;
		backtracking(s, 0, k);


		cout << '#' << num++ << ' ' << ans << '\n';
	}

	return 0;
}

