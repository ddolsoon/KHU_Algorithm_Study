// 개구리뛰기(삼성 SCPC 1회 예선).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <cstdio>

using namespace std;


int Answer;
int a[1000001];

int main(void)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	// freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin >> n;
		/////////////////////////////////////////////////////////////////////////////////////////////
		//개구리가 건널 돌 다리
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int k;
		cin >> k;	//최대 거리

		int cur = 0;
		for (int i = 1; i <= n; i++) {

			if (cur + k < a[i]) {
				cur = a[i - 1];
				Answer += 1;
			}
		}
		Answer += 1;

		for (int i = 1; i <= n; i++) {
			if (a[i + 1] - a[i] > k)
				Answer = -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).


		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
		
		Answer = 0;
	}

	return 0;//Your program should return 0 on normal termination.
}
