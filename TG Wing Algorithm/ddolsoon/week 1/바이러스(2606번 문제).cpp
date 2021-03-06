// 바이러스(2606번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

vector<int> computer[100];
bool check[100];

int ans = 0;

void dfs(int start) {

	check[start] = true;

	for (int y = 0; y < computer[start].size(); y++) {
		int next = computer[start][y];
		if (!check[next]) {
			ans += 1;
			check[next] = true;
			dfs(next);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		computer[u].push_back(v);
		computer[v].push_back(u);
	}

	dfs(1);

	cout << ans << '\n';

    return 0;
}

