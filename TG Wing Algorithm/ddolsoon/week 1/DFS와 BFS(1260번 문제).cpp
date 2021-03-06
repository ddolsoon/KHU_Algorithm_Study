// DFS와 BFS(1260번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool check[1001];

void dfs(int node) {

	cout << node << ' ';
	check[node] = true;

	for (int y = 0; y < graph[node].size(); y++) {
		int next = graph[node][y];
		if (!check[next]) {
			check[next] = true;
			dfs(next);
		}
	}

}

void bfs(int node) {

	queue<int> q;
	
	q.push(node);
	check[node] = true;

	while (!q.empty()) {

		int next = q.front();
		cout << next << ' ';
		q.pop();
		for (int y = 0; y < graph[next].size(); y++) {
			int z = graph[next][y];
			if (!check[z]) {
				check[z] = true;
				q.push(z);
			}
		}
	}

}

int main()
{
	int n, m, start;
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> start;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v); // 무방향 그래프
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	dfs(start);
	cout << '\n';
	memset(check, false, sizeof(check));
	bfs(start);
	cout << '\n';

	return 0;
}

