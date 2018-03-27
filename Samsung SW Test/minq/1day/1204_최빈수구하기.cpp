#include <iostream>
using namespace std;

int main()
{

	int testCaseNum;
	int max;
	int maxIndex;
	int score;

	for(int i=1; i<= 10; i++)
	{ 
		int forCount[101] = { 0 };
		max = 0;
		for (int j=0; j<=1000; j++)
		{
			if (j == 0)
			{
				cin >> testCaseNum;
				continue;
			}
			scanf("%d", &score);
			forCount[score]++;
		}
		for (int k = 1; k < 101; k++)
		{
			if (forCount[k] >= max)
			{
				max = forCount[k];
				maxIndex = k;
			}
		}
		cout << "#" << testCaseNum << " " << maxIndex << endl;

	}
	return 0;
}