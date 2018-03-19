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
		if (realExerciseTime < minimumExerciseTime) //실제 운동한 시간이 최소운동시간 보다 적다면.
		{
			answer = minimumExerciseTime - realExerciseTime;
		}
		else { // 실제 운동한 시간이 최소운동시간 보다 많다면.
			if (realExerciseTime < maximumExerciseTime) //최대 운동시간 보다 적다면.
			{
				answer = 0;
			}
			else {// 최대 운동시간 보다 많다면.
				answer = -1;
			}
		}
		cout << '#' << i << ' ' << answer << endl;
	}
	return 0;
}