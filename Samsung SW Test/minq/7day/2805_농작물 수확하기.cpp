#include <iostream>
#include <cstring>
using namespace std;
char charFarm[50][50];
int farm[50][50];
int main()
{
	int sum;
	int farmSize;
	int testCaseSize;
	cin >> testCaseSize;
	for (int T = 1; T <= testCaseSize; T++)
	{
		sum = 0;
		memset(farm, 0, sizeof(farm));
		memset(charFarm, '0', sizeof(charFarm));
		cin >> farmSize;
		for (int i = 1; i <= farmSize; i++)
		{
			for (int j = 1; j <= farmSize; j++)
			{
				cin >> charFarm[i][j];
				farm[i][j] = charFarm[i][j] - 48;
			}
		}
	for (int i = 1; i <= farmSize; i++)
	{
		//중앙 포함 위.
		for (int j = i; j <= farmSize-i+1; j++)
		{
			sum+=farm[farmSize / 2 + 2 - i][j];
		}

		//중앙 미포함 아래.
		for (int k = i+1; k<=farmSize-i; k++)
		{
			sum += farm[farmSize / 2 + 1 + i][k];
		}
	}
	cout << '#' << T << ' ' << sum << endl;
	}
}