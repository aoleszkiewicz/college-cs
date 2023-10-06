def fibb_iterate(n):
    if n < 2:
        return n
    else:
        a, b = 0, 1
        for i in range(0, n):
            result = a + b
            a = b
            b = result
            print(result)


def fibb_recursion(n):
    if n < 2:
        return n
    else:
        return fibb_recursion(n - 1) + fibb_recursion(n - 2)

