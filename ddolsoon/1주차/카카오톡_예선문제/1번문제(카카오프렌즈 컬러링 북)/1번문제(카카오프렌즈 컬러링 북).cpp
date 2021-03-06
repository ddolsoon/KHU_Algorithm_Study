
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int check[100][100];
int group[100][100];
int ans[100 * 100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void init(int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = 0;
			group[i][j] = 0;
			ans[i * n + j] = 0;
		}
	}
}

void bfs(int x, int y, int cnt, vector<vector<int>> picture, int m, int n) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	int color = picture[x][y]; //컬러링북 색깔
	group[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (picture[nx][ny] == color && group[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = cnt;
				}
			}
		}

	}

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	int max_size_of_one_area = 0;
	int number_of_area = 0;

	vector<int> answer(2);
	init(m, n);	//전역변수 초기화

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && group[i][j] == 0) {
				bfs(i, j, ++number_of_area, picture, m, n);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ans[group[i][j]] += 1;
		}
	}

	max_size_of_one_area = ans[1];
	for (int i = 2; i < m * n; i++) {
		if (max_size_of_one_area < ans[i]) {
			max_size_of_one_area = ans[i];
			cout << ans[i] << endl;
		}
	}


	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	//cout << answer[0] << endl;
	//cout << answer[1] << endl;

	return answer;
}

int main()
{
	vector<vector<int>> picture;
	/**
	intput case 1
	6 4
	1 1 1 0
	1 1 1 0
	0 0 0 1
	0 0 0 1
	0 0 0 1
	0 0 0 1

	intput case 2
	6 4
	1 1 1 0
	1 2 2 0
	1 0 0 1
	0 0 0 1
	0 0 0 3
	0 0 0 3

	*/
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		vector<int> element(n);
		picture.push_back(element);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> picture[i][j];
		}
	}

	solution(m, n, picture);

	cout << endl << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << group[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}

