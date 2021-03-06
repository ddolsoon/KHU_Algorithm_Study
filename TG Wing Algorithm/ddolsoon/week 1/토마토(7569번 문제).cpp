// 토마토(7569번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <queue>

using namespace std;


struct Point {
	int x;
	int y;
	int z;

};

queue<Point> q;

int farm[100][100][100];
int dist[100][100][100];

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int m, n, h;


void dfs() {

	while (!q.empty()) {

		int now_x = q.front().x;
		int now_y = q.front().y;
		int now_z = q.front().z;
		q.pop();

		for (int k = 0; k < 6; k++) {

			int nx = now_x + dx[k];
			int ny = now_y + dy[k];
			int nz = now_z + dz[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h) {
				if (farm[nx][ny][nz] == 0 && dist[nx][ny][nz] == -1) {
					dist[nx][ny][nz] = dist[now_x][now_y][now_z] + 1;
					Point p;
					p.x = nx;
					p.y = ny;
					p.z = nz;
					q.push(p);
				}
			}
		}

	}
}



int main()
{

	cin >> m >> n >> h;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> farm[i][j][k];
				dist[i][j][k] = -1;
			}
		}
	}


	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j][k] == 1) {
					Point p;
					p.x = i;
					p.y = j;
					p.z = k;

					q.push(p);
					dist[i][j][k] = 0;
				}
			}
		}
	}

	bool isAllRope = true;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j][k] == 0) {
					isAllRope = false;
				}
			}
		}
	}
	if (isAllRope) {
		cout << '0' << '\n';
	}

	dfs();
	/*for (int k = 0; k < h; k++) {
	for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	cout << dist[i][j][k] << '\t';
	}
	cout << '\n';
	}
	cout << '\n';
	}*/

	int ans = -1;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ans < dist[i][j][k]) {
					ans = dist[i][j][k];
				}
			}
		}
	}

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j][k] == 0 && dist[i][j][k] == -1) {
					ans = -1;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
