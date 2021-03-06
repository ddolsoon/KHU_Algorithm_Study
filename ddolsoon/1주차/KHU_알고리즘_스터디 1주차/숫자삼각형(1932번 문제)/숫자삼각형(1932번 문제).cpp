// 숫자삼각형(1932번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int d[501][501];
int a[501][501];
int max(int x, int y) {
	return (x > y) ? x : y;
}

// 해결!

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	//DP 계산
	d[1][1] = a[1][1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
		}
	}

	long long ans = d[n][1];
	for (int i = 2; i <= n; i++) {
		if (ans < d[n][i]) {
			ans = d[n][i];
		}
	}

	cout << ans << endl;

    return 0;
}

