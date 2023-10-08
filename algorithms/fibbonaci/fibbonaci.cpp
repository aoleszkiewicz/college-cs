int fibb_iterate(int n) {
    if (n <= 1) {
        return n;
    } else {
        int num1 = 0, num2 = 1;
        for (int i = 2; i <= n; ++i) {
            int result = num1 + num2;
            num1 = num2;
            num2 = result;
            std::cout << num2 << std::endl;
        }
        return num2;
    }
}

int fibb_recurrence(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibb_recurrence(n - 1) + fibb_recurrence(n - 2);
    }
}