// 1979. 어디에 단어가 들어갈 수 있을까 D2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

int arr[15][15];
bool check[15][15];
int dx[2] = { 0,1};
int dy[2] = { 1,0};
int n, k;

int getWordInput(int x, int y, int length) {

	int count = 1;
	int result = 0;

	check[x][y] = true;
	if (arr[x][y] == 0) {
		return 0;
	}
	for (int k = 0; k < 2; k++) {
		int nx = dx[k] + x;
		int ny = dy[k] + y;

		//맞은편이 0인가?
		bool isCorrectLength = true;
		if (0 <= nx - (dx[k] * 2) && nx - (dx[k] * 2) < n && 0 <= ny - (dy[k] * 2) && ny - (dy[k] * 2) < n) {
			if (arr[nx - (dx[k] * 2)][ny - (dy[k] * 2)] == 1) {

				isCorrectLength = false;
			}
		}

		for (int i = 0; i < length - 1; i++) {
			if (0 <= nx + (dx[k] * i) && nx + (dx[k] * i) < n 
				&& 0 <= ny + (dy[k] * i) && ny + (dy[k] * i) < n) {
				if (arr[nx + (dx[k] * i)][ny + (dy[k] * i)] == 1 &&
					check[nx + (dx[k] * i)][ny + (dy[k] * i)] == false) {

					count += 1;
				}
			}
		}

		//혹시, 3칸 맞추고 다음칸도 1인가?
		if (0 <= nx + (dx[k] * (length - 1)) && nx + (dx[k] * (length - 1))< n 
			&& 0 <= ny + (dy[k] * (length - 1)) && ny + (dy[k] * (length - 1)) < n) {
			if (arr[nx + (dx[k] * (length-1))][ny + (dy[k] * (length-1))] == 1) {
				isCorrectLength = false;
			}
		}
		

		//cout << "(x,y) count : " << "(" << x << "," << y << ")" << ' ' << count << endl;
		if (isCorrectLength && count == length) {
			result += 1;
		}
		count = 1;
	}
	//cout << "(x,y) result : " << "(" << x + 1 << "," << y + 1 << ")" << ' ' << result << endl;
	return result;
}

int main()
{
	int t;
	int num = 1;
	cin >> t;
	while (t--) {

		memset(check, false, sizeof(check));

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans += getWordInput(i, j, k);
			}
		}


		cout << '#' << num++ << ' ' << ans << '\n';

	}


	return 0;
}

