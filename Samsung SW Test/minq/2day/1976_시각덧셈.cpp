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
		answerTime = (firstTime + secondTime) % 12;
		answerMinute = firstMinute + secondMinute;
		if (answerMinute >= 60)
		{
			answerTime += 1;
			answerMinute %= 60;
		}
		
		cout << '#' << i << " " << answerTime << " " << answerMinute << endl;
	}

	return 0;
}