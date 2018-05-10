import utility
import queue

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


def BFS(a, v):
    q = queue.Queue()
    q.put(v)
    while not (q.empty()):
        x = q.get()
        print(x)
        visited[x] = 1
        for y in range(0, n):  # 다음 방문할 노드 점검
            if a[x][y] == 1 and visited[y] == 0:
                q.put(y)
                visited[y] = 1


BFS(a, 0)
