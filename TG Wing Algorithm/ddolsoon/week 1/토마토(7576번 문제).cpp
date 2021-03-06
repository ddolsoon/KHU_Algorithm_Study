#include <iostream>
#include <queue>

using namespace std;

int farm[1000][1000];
bool check[1000][1000];

queue<pair<int, int>> q;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m;

void bfs() {


	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		// cout << x << "," << y << '\n';
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == false && farm[nx][ny] == 0) {
					farm[nx][ny] = farm[x][y] + 1;

					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}

int main()
{

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> farm[i][j];
		}
	}

	//저장될떄부터 토마토가 모두익어있다?
	bool isAllipen = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (farm[i][j] == 0) {
				isAllipen = false;
			}
		}
	}

	if (isAllipen) {
		cout << '0' << '\n';
		return 0;
	}

	//익은 토마토를 넣어주자
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (farm[i][j] == 1) {
				check[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}

	//토마토 익히기
	bfs();

	/*for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	cout << farm[i][j] << ' ';
	}
	cout << '\n';
	}*/

	int ans = farm[0][0];

	bool isNotRapen = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans < farm[i][j]) {
				ans = farm[i][j];
			}

			if (farm[i][j] == 0) {
				isNotRapen = true;
			}
		}
	}

	if (isNotRapen) {
		cout << "-1" << '\n';
	}
	else {
		cout << ans - 1 << '\n';
	}
	return 0;
}