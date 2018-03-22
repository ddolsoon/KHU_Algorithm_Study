#include<iostream>
#include<cstring>
using namespace std;

//100�� ������ �Ҽ����� ��� ����ϴ� ����.
// �Ҽ��� ������ ������ ���� ������ Ȯ���ϸ� ���ϸ� �ð��ʰ� �߻�!
// �����佺 �׳׽��� ü �˰����� ����Ͽ� ���� �ð� �� ���� �� �ִ�.
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


