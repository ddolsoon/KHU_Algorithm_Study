// 4012. 요리사 문제.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>


using namespace std;

bool check[21];
int s[21][21];
int ans;

int INF = 1000000000;

int abs(int a) {
	return a > 0 ? a : -a;
}

int min(int a, int b) {
	return a > b ? b : a;
}

void recursion(int N, int cnt, int food) {

	if (cnt == N) { //현재까지 체크한 식재료 개수가 N개 (음식 만들준비 완료)
		int A = 0, B = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == j) { //재료가 같으면 안돼!
					continue;
				}

				if (check[i] && check[j])
					A += s[i][j];

				if (!check[i] && !check[j])
					B += s[i][j];
			}
		}
		ans = min(ans, abs(A - B)); //음식의 맛의 차이 최소값 구하기 (정답 도출)

		return;
	}

	if (food > 0) {
		check[cnt] = true;
		recursion(N, cnt + 1, food - 1); //cnt 변수 식재료가 A에 사용된다.
		check[cnt] = false;
	}

	recursion(N, cnt + 1, food); // B음식에 식재료가 사용된다.
}

int main()
{
	int t;
	cin >> t;
	int num = 1;
	while (t--) {

		int N;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> s[i][j];
			}
		}

		ans = INF;
		recursion(N, 0, N / 2);

		printf("#%d %d \n", num++, ans);
	}

	return 0;
}

