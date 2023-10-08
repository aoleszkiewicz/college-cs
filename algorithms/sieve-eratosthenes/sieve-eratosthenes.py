def sieve(n):
    numbers = [True for _ in range(n)]
    primes = []
    for i in range(len(numbers)):
        if i <= 1:
            numbers[i] = False
        else:
            if numbers[i]:
                primes.append(i)
                for j in range(i, len(numbers), i):
                    numbers[j] = False

    return primes