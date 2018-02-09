// 상자넣기(1965번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int d[1001];
int a[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}


	for (int i = 1; i <= n; i++){
		d[i] = 1;
		int temp = d[1];
		for (int j = 1; j < i; j++) {			
			if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}

	}

	long long ans = d[1];
	for (int i = 2; i <= n; i++) {
		if (ans < d[i])
			ans = d[i];
	}

	cout << ans << endl;


    return 0;
}

