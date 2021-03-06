// 1954. 달팽이 숫자 D2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <cstring>

using namespace std;

int direction[4] = { 0,1,2,3 }; // Right Down Left Up

int arr[10][10];

int main()
{
	int t;
	int num = 1;
	cin >> t;
	int cur = 0;
	int x = 0, y = 0;
	while (t--) {

		x = 0;
		y = 0;
		cur = 0;

		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		int i = 1;
		while(i <= n * n) {

			if (n == 1) { // 2번째 야매
				arr[x][y] = 1;
				break;
			}

			arr[x][y] = i;
			if (i == n*n - 1) { //야매 쓴 부분
				cur += 1;
				int curDirection = direction[cur % 4];
				switch (curDirection) {
				case 0:
					y++;
					break;
				case 1:
					x++;
					break;
				case 2:
					y--;
					break;
				case 3:
					x--;
					break;
				}
				
				i++;
				arr[x][y] = i;
				//cout << cur << endl;
				break;
			}

			int curDirection = direction[cur % 4];
			switch (curDirection) {
			case 0:
				if (y + 1 < n)
					if (arr[x][y + 1] == 0) {
						y++;
						i++;
					}
					else cur++;
				else
					cur++;
				break;
			case 1:
				if (x + 1 < n)
					if (arr[x + 1][y] == 0) {
						x++;
						i++;
					}
					else cur++;
				else
					cur++;
				break;
			case 2:
				if (y - 1 >= 0)
					if (arr[x][y - 1] == 0) {
						y--;
						i++;
					}
					else
						cur++;
				else
					cur++;
				break;
			case 3:
				if (x - 1 >= 0)
					if (arr[x - 1][y] == 0) {
						x--;
						i++;
					}
					else
						cur++;
				else
					cur++;
				break;
			}
		}

		cout << '#' << num++ << ' ' << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
    return 0;
}

