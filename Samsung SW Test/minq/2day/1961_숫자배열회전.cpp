#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int testCaseNum;
	cin >> testCaseNum;
	int matrixSize;
	int matrix[7][7];
	for (int i = 1; i <= testCaseNum; i++)
	{
		scanf("%d", &matrixSize);
		//memset(matrix, 0, sizeof(int)*49);
		int matrix[7][7] = { 0 };
		for (int j = 0; j < matrixSize; j++)
		{
			for (int k = 0; k < matrixSize; k++)
			{
				scanf("%d", &matrix[j][k]); //question.
			}
		}
		cout << "#" << i << endl;
		
		for (int l = 0; l < matrixSize; l++)
		{
			for (int m = 0; m < matrixSize; m++) //1¿­
			{
				cout << matrix[matrixSize -1-m][l];
			}
			cout << " ";
			for (int n = 0; n < matrixSize; n++)//2¿­
			{
				cout << matrix[matrixSize - 1 - l][matrixSize - 1 - n];
			}
			cout << " ";
			for (int h = 0; h < matrixSize; h++) //3¿­
			{
				cout << matrix[h][matrixSize - 1 - l];
			}
			cout << endl;
		}
	}
	return 0;
}