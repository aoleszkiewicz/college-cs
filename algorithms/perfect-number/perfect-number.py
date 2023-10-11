def is_perfect_number(n):
    sum_temp = 0
    for i in range(1, n - 1):
        if n % i == 0:
            sum_temp += i

    return True if sum_temp == n else False