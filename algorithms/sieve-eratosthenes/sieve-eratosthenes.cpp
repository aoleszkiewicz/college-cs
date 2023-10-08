std::vector<int> sieve(int n) {
    std::vector<bool> numbers(n, true);
    std::vector<int> primes;
    for (int i = 1; i < n; i++) {
        if (i <= 1) {
            numbers[i] = false;
        }
        else {
            if (numbers[i]) {
                primes.push_back(i);
                for (int j = i; j < n; j += i) {
                    numbers[j] = false;
                }
            }
        }
    }

    return primes;
}