#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {1,-1,-1,1};
int dy[4] = {1,1,-1,-1};
bool isAte[101];
int dessertArea[21][21];
void dfs(int startY, int startX, int nowY, int nowX, int direction, int count);
int answer;
int squareWidth;
int main()
{
	int testCaseSize;
	
	cin >> testCaseSize;
	for (int T = 1; T <= testCaseSize; T++)
	{
		answer = -1;
		cin >> squareWidth;
		for (int i = 0; i < squareWidth; i++)
			for (int j = 0; j < squareWidth; j++)
				scanf("%d", &dessertArea[i][j]);

		for (int y = 0; y < squareWidth; y++)
		{
			for (int x = 0; x < squareWidth; x++)
			{
					memset(isAte, 0, sizeof(isAte));
					dfs(y, x, y, x, 0, 1);
			}
		}
		if (answer < 4)
			answer = -1;
		cout << "#" << T << " " << answer<<endl;
	}
}
void dfs(int startY, int startX, int nowY, int nowX, int direction, int count)
{
	if (direction == 3 && nowY == startY && nowX == startX)
	{
		answer = max(answer, count - 1);
		return;
	}
	if (isAte[dessertArea[nowY][nowX]] == 1)
		return;
	isAte[dessertArea[nowY][nowX]] = true;

	int noPlusDirectionY = nowY + dy[direction];
	int noPlusDirectionX = nowX + dx[direction];
	
		if (noPlusDirectionX >=0 && noPlusDirectionX<squareWidth &&noPlusDirectionY >=0 && noPlusDirectionY<squareWidth)
		{
			dfs(startY, startX, noPlusDirectionY, noPlusDirectionX, direction, count + 1);
		}
		if (direction != 3)
		{
			int plusDirectionY = nowY + dy[direction + 1];
			int plusDirectionX = nowX + dx[direction + 1];
			if (plusDirectionX >= 0 && plusDirectionX < squareWidth &&plusDirectionY >= 0 && plusDirectionY < squareWidth)
				dfs(startY, startX, plusDirectionY, plusDirectionX, direction + 1, count + 1);
		}
	isAte[dessertArea [nowY][nowX]] = 0;
	
}