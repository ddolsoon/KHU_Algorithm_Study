import utility

e = {0: [1, 2, 3], 1: [2, 5], 2: [3, 4, 5, 6], 3: [4, 6], 4: [6, 7]}
n = 8
a = [[0 for j in range(0, n)] for i in range(0, n)]

for i in range(0, n - 1):
    for j in range(i + 1, n):
        if i in e:
            if j in e[i]:
                a[i][j] = 1
                a[j][i] = 1
utility.printMatrix(a)

visited = n * [0]


def DFS(a, v):
    visited[v] = 1
    print(v)
    for x in range(0, n):  # 다음 방문할 노드 점검
        if a[v][x] == 1 and visited[x] == 0:
            DFS(a, x)


DFS(a, 0)
