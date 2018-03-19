#include <iostream>
#include <cstring>
using namespace std;
// bool isPossibleNum[1000] = {false;}
// 한 자리 수 탐색, 두 자리 수 탐색, 세 자리 수 탐색하여 가능한 숫자는 true로 토글.
// 각 자리 수 탐색이 끝날 때 마다 isPossibleNum에 인덱스에 대응되는 숫자가
// false인지 확인 한 후 있다면 그 수가 답. 없다면 다음 자리 수 탐색으로.

bool isPossibleNum[1000];
int Sequence[1000];
int sequenceSize;
int answer;
int main()
{
	int testCaseSize;
	cin >> testCaseSize;
	for (int T = 1; T <= testCaseSize; T++)
	{
		memset(isPossibleNum, 0, sizeof(isPossibleNum));
		memset(Sequence, 0, sizeof(Sequence));
		answer = -1;//answer값 초기화.
		scanf("%d", &sequenceSize);
		for (int i = 0; i < sequenceSize; i++)
		{
			scanf("%d", &Sequence[i]);
			isPossibleNum[Sequence[i]] = true; //입력을 받은 후, 가능한 한 자리수 마킹.
		}
		//가능하지 않은 한 자리 수가 있는지 확인.
		for (int i = 0; i < 10; i++)
		{
			if (isPossibleNum[i] == false)
			{
				answer = i;
				break;
			}
		}
		//가능한 두 자리 수 마킹.
		if(answer==-1)
		{
		for (int i = 0; i < sequenceSize - 1; i++)
		{
			isPossibleNum[Sequence[i] * 10 + Sequence[i + 1]] = true;
		}
		//가능하지 않은 두 자리 수가 있는지 확인.
		for (int i = 10; i < 100; i++)
		{
			if (isPossibleNum[i] == false)
			{
				answer = i;
				break;
			}
		}
		}
		//가능한 세 자리 수 마킹.
		if(answer==-1){
		for (int i = 0; i < sequenceSize - 2; i++)
		{
			isPossibleNum[Sequence[i] * 100 + Sequence[i + 1]*10+Sequence[i+2]] = true;
		}
		//가능하지 않은 세 자리 수가 있는지 확인.
		for (int i = 100; i < 1000; i++)
		{
			if (isPossibleNum[i] == false)
			{
				answer = i;
				break;
			}
		}
		}
		cout << '#' << T << ' ' << answer << endl;
	}
	return 0;
}