def printMatrix(d):
    m = len(d)
    n = len(d[0])

    for i in range(0, m):
        for j in range(0, n):
            print("%4d" % d[i][j], end=" ")
        print()


# print float matrix
def printMatrixF(d):
    n = len(d[0])
    for i in range(0, n):
        for j in range(0, n):
            print("%5.2f" % d[i][j], end=" ")
        print()


def print_inOrder(root):
    if not root:
        return
    print_inOrder(root.l_child)
    print(root.data)
    print_inOrder(root.r_child)


def print_preOrder(root):
    if not root:
        return
    print(root.data)
    print_preOrder(root.l_child)
    print_preOrder(root.r_child)


def print_postOrder(root):
    if not root:
        return

    print_postOrder(root.l_child)
    print_postOrder(root.r_child)
    print(root.data)
