#include <iostream>
using namespace std;

int main()
{
	int testCaseSize;
	int minimumExerciseTime;
	int maximumExerciseTime;
	int realExerciseTime;
	int answer;
	
	cin >> testCaseSize;
	
	for (int i = 1; i <= testCaseSize; i++)
	{
		cin >> minimumExerciseTime >> maximumExerciseTime >> realExerciseTime;
		if (realExerciseTime < minimumExerciseTime) //���� ��� �ð��� �ּҿ�ð� ���� ���ٸ�.
		{
			answer = minimumExerciseTime - realExerciseTime;
		}
		else { // ���� ��� �ð��� �ּҿ�ð� ���� ���ٸ�.
			if (realExerciseTime < maximumExerciseTime) //�ִ� ��ð� ���� ���ٸ�.
			{
				answer = 0;
			}
			else {// �ִ� ��ð� ���� ���ٸ�.
				answer = -1;
			}
		}
		cout << '#' << i << ' ' << answer << endl;
	}
	return 0;
}