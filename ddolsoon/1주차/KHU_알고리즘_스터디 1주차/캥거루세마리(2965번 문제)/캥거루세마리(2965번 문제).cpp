// 캥거루세마리(2965번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int main()
{
	//dp로 꼭 풀어야할까?

	int a, b, c;
	cin >> a >> b >> c;
	int d1, d2;

	d1 = b - a - 1;
	d2 = c - b - 1;

	cout << max(d1, d2) << endl;

    return 0;
}

