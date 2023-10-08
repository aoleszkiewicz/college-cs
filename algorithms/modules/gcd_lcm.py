# Euclidean algorithm for Greatest Common Divisor
def gcd(m, n) -> int:
    if m > n:
        a, b = m, n
    else:
        a, b = n, m

    while b != 0:
        rest = a % b
        a = b
        b = rest
    return a


# Recurrence Euclidean algorithm for Greatest Common Divisor
def gcd_recurrence(m, n) -> int:
    if n > 0:
        return gcd_recurrence(n, m % n)
    return m


# Least Common Multiple
def lcm(m, n) -> int:
    return int(m * n / gcd(m, n))
