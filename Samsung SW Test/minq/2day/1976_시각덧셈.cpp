#include<iostream>
using namespace std;

int main()
{
	int testCaseNum;
	int firstTime,firstMinute;
	int secondTime, secondMinute;
	int answerTime, answerMinute;
	cin >> testCaseNum;

	for(int i=1; i<=testCaseNum; i++)
	{ 
		answerTime = 0;
		answerMinute = 0;
		cin >> firstTime >> firstMinute >> secondTime >> secondMinute;
		answerMinute = firstMinute + secondMinute;
		if (answerMinute >= 60)
		{
			answerTime += 1;
			answerMinute %= 60;
		}
		answerTime += (firstTime + secondTime) % 12;
		if (answerTime == 0)
			answerTime = 12;
		cout << '#' << i << " " << answerTime << " " << answerMinute << endl;
	}

	return 0;
}