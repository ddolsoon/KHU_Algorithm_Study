// 1948. 날짜 계산기 D2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int days[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int t;
	int num = 1;
	cin >> t;
	while (t--) {

		int first_mon;
		int first_days;
		int second_mon;
		int second_days;
		cin >> first_mon >> first_days >> second_mon >> second_days;

		int count = 0;

		if (first_mon != second_mon) {
			count += (days[first_mon] - first_days + 1);
			count += (second_days);
		}
		else {
			count += (second_days - first_days + 1);
		}

		for (int i = first_mon + 1; i <= second_mon - 1; i++) {
			count += days[i];
		}


		cout << '#' << num++ << ' ' << count << '\n';
	}


    return 0;
}

