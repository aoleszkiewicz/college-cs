# Fibbonaci sequence using iteration
def fibb_iterate(n) -> int:
    if n <= 1:
        return n
    else:
        num1, num2 = 0, 1
        for i in range(0, n):
            result = num1 + num2
            num1 = num2
            num2 = result
            return num2


# Fibbonaci sequence using recursion
def fibb_rec(n) -> int:
    if n <= 1:
        return n
    else:
        return fibb_rec(n-1) + fibb_rec(n-2)