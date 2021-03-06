// 14502번 문제(연구소).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <cstring>

using namespace std;

int map[8][8];
int wall_map[8][8];
int check[8][8];

int n, m;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int safe_zone_count = 0;
int ans = 0;

void init_map() {

	memset(check, 0, sizeof(check));
	safe_zone_count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			wall_map[i][j] = map[i][j];
		}
	}
}

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << wall_map[i][j] << ' ';
		}
		cout << '\n';
	}

}

void bfs(int x, int y)
{
	check[x][y] = 1;
	wall_map[x][y] = 2;

	for (int k = 0; k < 4; k++) {
		int nx = dx[k] + x;
		int ny = dy[k] + y;
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (check[nx][ny] == 0 && wall_map[nx][ny] == 0) {
				check[nx][ny] = 1;
				wall_map[nx][ny] = 2;
				bfs(nx, ny);
			}
		}
	}
}


int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	//벽을 세워봅시당.
	for (int k = 0; k < n * m - 2; k++) {
		for (int l = k + 1; l < n * m - 1; l++) {
			for (int z = l + 1; z < n * m; z++) {

				init_map();

				if (wall_map[z / m][z % m] == 0 && wall_map[l / m][l % m] == 0 && wall_map[k / m][k % m] == 0) {
					wall_map[z / m][z % m] = 1;
					wall_map[l / m][l % m] = 1;
					wall_map[k / m][k % m] = 1;

					//바이러스 전파
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if (wall_map[i][j] == 2 && check[i][j] == 0) {
								bfs(i, j);
							}
						}
					}

					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if (wall_map[i][j] == 0) {
								safe_zone_count += 1;
							}
						}
					}

					if (ans < safe_zone_count) {
						ans = safe_zone_count;
					}
					//cout << "안전존 갯수 : " << ans << '\n';
					//print();

				}
	
			}
		}
	}



	cout << ans << '\n';

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}



	return 0;
}

