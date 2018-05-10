def promising(i, col):
    k = 0
    switch = True
    while (k < i and switch == True):
        if (col[i] == col[k] or abs(col[i] - col[k]) == i - k):
            switch = False
        k += 1

    return switch


def queens(n, i, col):
    if promising(i, col) == True:
        if (i == n - 1):
            print(col)
        else:
            for j in range(0, n):
                col[i + 1] = j
                queens(n, i + 1, col)


n = 9
col = n * [0]
queens(n, -1, col)