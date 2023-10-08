// Euclidean algorithm that searches GCD
int gcd(int m, int n) {
    // Shorthand for if else statement, checks which value is greater.
    int a, b = (m > n ? m, n : n, m);
    int rest;
    
    while (b != 0) {
        rest = a % b;
        a = b;
        b = rest;
    }
    
    return a;
}

// Recurrence Euclidean algorithm implementation that searches for GCD
int gcd_rec(int m, int n) {
    if (n > 0) {
        return gcd_rec(n, m % n);
    }
    return m;
}

// Algorithm that searches for LCM and uses GCD algorithm
int lcm(int m, int n) {
    return (m * n / gcd(m, n));
}