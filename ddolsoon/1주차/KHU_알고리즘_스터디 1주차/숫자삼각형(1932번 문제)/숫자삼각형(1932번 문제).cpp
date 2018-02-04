// 숫자삼각형(1932번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int d[501][2];
int max(int x, int y) {
	return (x > y) ? x : y;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> a;

	for (int i = 0; i < n; i++) {
		vector<int> element(i+1);
		a.push_back(element);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size();j++) {
			cin >> a[i][j];
		}
	}

	
	//DP 계산
	d[0][0] = a[0][0];
	d[0][1] = 0;
	cout << "테스트" << endl;

	long long ans = 0;
	for (int i = 1; i <= n; i++) {

		d[i][0] = d[i - 1][0] + max(a[i][d[i - 1][1]], a[i][d[i - 1][1] + 1]);
		if (a[i][d[i - 1][1]] > a[i][d[i - 1][1] + 1]) {
			d[i][1] = d[i - 1][1];
		}
		else {
			d[i][1] = d[i - 1][1] + 1;
		}
		cout << d[i][0] << endl;
	}

	cout << d[n - 1] << endl;

    return 0;
}

