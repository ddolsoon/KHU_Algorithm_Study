// 미로 탐색(2178번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <queue>

using namespace std;

int maze[100][100];
int check[100][100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m;

void bfs() {
	
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = 1;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		//cout << x << "," << y << '\n';
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == 0 && maze[nx][ny] == 1) {
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}

int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	bfs();
	
	cout << check[n - 1][m - 1] << '\n';

    return 0;
}

