#include <iostream>

bool isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return true;
    }

    return false;
}
