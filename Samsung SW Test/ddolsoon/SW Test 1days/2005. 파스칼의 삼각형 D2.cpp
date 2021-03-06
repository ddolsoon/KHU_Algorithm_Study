// 2005. 파스칼의 삼각형 D2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int d[11][11];

int main()
{
	int t;
	cin >> t;
	int num = 1;
	while (t--) {
		int n;
		cin >> n;

		//파스칼 삼각혐 초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = 1;
			}
		}

		for (int i = 3; i <= n; i++) {
			for (int j = 2; j <= i - 1; j++) {
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			}
		}


		//출력
		cout << '#' << num++ << '\n';

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cout << d[i][j] << ' ';
			}
			cout << '\n';
		}
	}
    return 0;
}

