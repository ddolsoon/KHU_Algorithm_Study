#include<iostream>
#include<cstring>
using namespace std;

//100만 이하의 소수들을 모두 출력하는 문제.
// 소수의 조건을 루프를 돌려 일일히 확인하며 구하면 시간초과 발생!
// 에라토스 테네스의 체 알고리즘을 사용하여 빠른 시간 내 구할 수 있다.
bool forCheck[1000001];

int main()
{
	memset(forCheck, 1, sizeof(forCheck));
	for (int i = 2; i < 1000000; i++)
	{
		for (int j = 2; i*j < 1000000; j++)
		{
			forCheck[i*j] = 0;
		}
	}

	for (int i = 2; i < 1000000; i++)
	{
		if (forCheck[i] == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}


