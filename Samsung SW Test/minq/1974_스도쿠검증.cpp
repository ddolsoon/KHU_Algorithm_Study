#include<iostream>
using namespace std;

int forInsert[9][9];
bool forCheck[10] = { 0 };
int main()
{
	int testCase;
	int isCorrect; // 맞으면 1
	cin >> testCase;

	for(int i=1; i<=testCase; i++)
	{	 
		isCorrect = 1; //초기화.

		for (int j = 0; j < 9; j++)
		{
			for (int k=0; k< 9; k++)
			{
				cin >> forInsert[j][k];
			}
		}

	//가로줄 확인.
		for (int k = 0; k < 9; k++)
		{
			bool forCheck[10] = { false };
			for (int l = 0; l < 9; l++)
			{
				forCheck[forInsert[k][l]] = true;//!forCheck[forInsert[k][l]];
			}
			for (int m = 1; m <= 9; m++)
			{
				if (forCheck[m] == false)
				{
				isCorrect = 0;
				break;
				}
			}
		}

	//세로줄 확인.
		if (isCorrect == 1)
		{
		
			for (int k = 0; k < 9; k++)
			{
				bool forCheck[10] = { false };
				for (int l = 0; l < 9; l++)
				{
					forCheck[forInsert[l][k]] = true;//!forCheck[forInsert[l][k]];
				}
				for (int m = 1; m <= 9; m++)
				{
					if (forCheck[m] == false)
					{
						isCorrect = 0;
						break;
					}
				}
			}
		}

	//3x3확인. 00 01 02 10 11 12 20 21 22 // 03 04 05
	if (isCorrect == 1)
	{
		int firstIndex = 0;
		int secondIndex = 0;
		for (int i = 0; i < 9; i++ )
		{
			bool forCheck[10] = { false };
			
			for(int j=0; j<3; j++)
			{ 
				for (int k = 0; k < 3; k++)
				{
					forCheck[forInsert[firstIndex+j][secondIndex+k]] = true;//!forCheck[forInsert[firstIndex+j][secondIndex+k]];
				}
			}

			for (int m = 1; m <= 9; m++)
			{
				if (forCheck[m] == false)
				{
					isCorrect = 0;
					break;
				}
			}
			if (secondIndex == 6)
			{
				firstIndex += 3;
				secondIndex = 0;
			}
			else
			{
				secondIndex += 3; 
			}
			
		}
	}


	cout << "#" << i << " " << isCorrect << endl;
	}
	return 0;
}