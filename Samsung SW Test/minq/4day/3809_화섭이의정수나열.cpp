#include <iostream>
#include <cstring>
using namespace std;
// bool isPossibleNum[1000] = {false;}
// �� �ڸ� �� Ž��, �� �ڸ� �� Ž��, �� �ڸ� �� Ž���Ͽ� ������ ���ڴ� true�� ���.
// �� �ڸ� �� Ž���� ���� �� ���� isPossibleNum�� �ε����� �����Ǵ� ���ڰ�
// false���� Ȯ�� �� �� �ִٸ� �� ���� ��. ���ٸ� ���� �ڸ� �� Ž������.

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
		answer = -1;//answer�� �ʱ�ȭ.
		scanf("%d", &sequenceSize);
		for (int i = 0; i < sequenceSize; i++)
		{
			scanf("%d", &Sequence[i]);
			isPossibleNum[Sequence[i]] = true; //�Է��� ���� ��, ������ �� �ڸ��� ��ŷ.
		}
		//�������� ���� �� �ڸ� ���� �ִ��� Ȯ��.
		for (int i = 0; i < 10; i++)
		{
			if (isPossibleNum[i] == false)
			{
				answer = i;
				break;
			}
		}
		//������ �� �ڸ� �� ��ŷ.
		if(answer==-1)
		{
		for (int i = 0; i < sequenceSize - 1; i++)
		{
			isPossibleNum[Sequence[i] * 10 + Sequence[i + 1]] = true;
		}
		//�������� ���� �� �ڸ� ���� �ִ��� Ȯ��.
		for (int i = 10; i < 100; i++)
		{
			if (isPossibleNum[i] == false)
			{
				answer = i;
				break;
			}
		}
		}
		//������ �� �ڸ� �� ��ŷ.
		if(answer==-1){
		for (int i = 0; i < sequenceSize - 2; i++)
		{
			isPossibleNum[Sequence[i] * 100 + Sequence[i + 1]*10+Sequence[i+2]] = true;
		}
		//�������� ���� �� �ڸ� ���� �ִ��� Ȯ��.
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