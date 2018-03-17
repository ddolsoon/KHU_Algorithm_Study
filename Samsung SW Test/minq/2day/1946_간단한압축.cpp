#include<iostream>
using namespace std;

char numChar[10]=""; //NULL로 초기화.
int charCount[10] = { 0 };
int main()
{
	int testCaseNum;
	int alphabetNum;
	int charCountSum;
	cin >> testCaseNum;
	for (int i = 1; i <= testCaseNum; i++)
	{
		char numChar[10] = "";//memset(numChar, 0x00, sizeof(char)*10); 컴파일오류발생.
		int charCount[10] = { 0 };//memset(charCount, 0, sizeof(int)*10); memset함수에서 오류발생.
		cin >> alphabetNum;
		charCountSum = 0;
		for (int j = 0; j < alphabetNum; j++)
		{
			cin >> numChar[j];
			cin >> charCount[j];
		}
		cout << "#" << i;
		for (int k = 0; k < 10; k++)
		{
			if(charCount[k]!=0)
			{ 
				for (int m = 0; m < charCount[k]; m++)
				{
					if (charCountSum % 10 == 0)
					{
						cout << endl;
					}
					cout << numChar[k];
					charCountSum++;
				}
			}
		}	
		cout << endl;
	}
	return 0;
}