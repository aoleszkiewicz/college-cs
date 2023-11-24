#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;


// 1 SPRAWOZDANIE
void sayHelloWorld() {
    cout << "Hello World" << endl;
}

int nwd(int a, int b) {
    int num1, num2 = a > b ? (a, b) : (b, a);
    int rest;
    while (b != 0) {
        rest = a % b;
        a = b;
        b = rest;
    }

    return a;
}

int nww(int a, int b) {
    return a * b/nwd(a, b);
}

int silnia_it(int power) {
    if (power < 2) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= power; i++) {
        result *= i;
    }
    return result;
}

int silnia_rec(int power) {
    if (power < 2) {
        return 1;
    }
    return power * silnia_rec(power - 1);
}

int pow(int n, int power) {
    int result = n;
    for (int i = 1; i < power; i++) {
        result *= n;
    }
    return result;
}

int sum(int n) {
    if (n > 10000 || n < 1000) {
        return 0;
    }

    int liczba1 = n / 1000;
    int liczba2 = n / 100;
    liczba2 %= 10;
    int liczba3 = n / 10;
    liczba3 %= 100;
    liczba3 %= 10;
    int liczba4 = n / 1;
    liczba4 %= 1000;
    liczba4 %= 100;
    liczba4 %= 10;

    return liczba1 + liczba2 + liczba3 + liczba4;
}

void findSmallest(const int numbers[], int size) {
    if (size <= 0) {
        cout << "Array can't be empty!" << endl;
    }

    int smallestNumber = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < smallestNumber) {
            smallestNumber = numbers[i];
        }
    }
    cout << smallestNumber << endl;
}

void findLargest(const int numbers[], int size) {
    if (size <= 0) {
        cout << "Array can't be empty!" << endl;
    }

    int largestNumber = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > largestNumber) {
            largestNumber = numbers[i];
        }
    }

    cout << largestNumber << endl;
}

void calculateMedium(const int numbers[], int size) {
    if (size <= 0) {
        cout << "Array can't be empty!" << endl;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    cout << (double)sum / size << endl;
}

void sumOfWholeArray(const int numbers[], int size) {
    if (size <= 0) {
        cout << "Array can't be empty!" << endl;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    cout << sum << endl;
}

void calculateMultiplesOfThree(const int numbers[], int size) {
    bool areMultiplesPresent = false;
    int numberOfMultiples = 0;

    for (int i = 0; i < size; i++) {
        if (numbers[i] % 3 == 0) {
            areMultiplesPresent = true;
            ++numberOfMultiples;
        }
    }

    cout << areMultiplesPresent << numberOfMultiples << endl;
}

void searchForNumber(const int numbers[], int size, int searchedNumber) {
    for (int i = 0; i < size; i++) {
        if (numbers[i] == searchedNumber) {
            cout << "Number found at index: " << i << endl;
        }
    }
}

void multiArrayOperator(int arrayOfNumbers[]) {
    int userChoice;
    cout << "Choose from 1 to 6, which option you would like to do with given array" << endl;
    cin >> userChoice;

    int sizeOfArray = sizeof(arrayOfNumbers)/sizeof(arrayOfNumbers[0]);

    switch (userChoice) {
        case 1:
            findLargest(arrayOfNumbers, sizeOfArray);
            break;
        case 2:
            findSmallest(arrayOfNumbers, sizeOfArray);
            break;
        case 3:
            calculateMedium(arrayOfNumbers, sizeOfArray);
            break;
        case 4:
            sumOfWholeArray(arrayOfNumbers, sizeOfArray);
            break;
        case 5:
            calculateMultiplesOfThree(arrayOfNumbers, sizeOfArray);
            break;
        case 6:
            int searchedNumber;
            cin >> searchedNumber;
            searchForNumber(arrayOfNumbers, sizeOfArray, searchedNumber);
            break;
    }

}

void calculateDelta(int a, int b, int c) {
    if (a != 0) {
        int d = (b*b) - 4*a*c;
        cout << (b*(-1)+sqrt(d))/(2*a) << endl;
        cout << (b*(-1)-sqrt(d))/(2*a) << endl;
    } else {
        cout << (-1)*c/b << endl;
    }
}

// SPRAWOZDANIE 2

void calculateTriangle(int side1, int side2, int side3) {
    if (side2 + side3 > side1 || side1 + side3 > side2 || side1 + side2 > side3) {
        float a;
        float area;

        a = (side1+side2+side3) / 2;
        area = sqrt(a * (a - side2) * (a - side2) * (a - side3));

        cout << "Pole: " << area << endl;
    } else {
        cout << "Nie da sie utworzyc trojkata z podanych bokow" << endl;
    }
}

void sieveEratosthenes(int n) {
    bool* numbers = new bool[n];
    for (int i = 0; i < n; ++i) {
        numbers[i] = true;
    }

    for (int i = 2; i < n; ++i) {
        if (numbers[i]) {
            cout << i << endl;
            for (int j = i * 2; j < n; j += i) {
                numbers[j] = false;
            }
        }
    }

    delete[] numbers;
}

int fibb(int n) {
    if (n <= 1) {
        return n;
    } else {
        int num1 = 0, num2 = 1;
        for (int i = 2; i <= n; ++i) {
            int result = num1 + num2;
            num1 = num2;
            num2 = result;
            cout << num2 << endl;
        }
        return num2;
    }
}

void calculator(int number1, int number2) {
    char calcOperator;
    cout << "Wprowadz operator, ktory chcesz uzyc dostepne (4) +, -, *, /" << endl;
    cin >> calcOperator;

    switch (calcOperator) {
        case '+':
            cout << number1 + number2 << endl;
            break;
        case '-':
            cout << number1 - number2 << endl;
            break;
        case '*':
            cout << number1 * number2 << endl;
            break;
        case '/':
            cout << number1 / number2 << endl;
            break;
        default:
            cout << "Wybrales niepoprawny operator operacyjny" << endl;
    }
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    int sqrtNum = (int)sqrt(number);
    for (int i = 2; i <= sqrtNum; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

void guessRandomizedNumber() {
    int i = 1;
    int r = (rand() % 15) + 1;

    int x;

    while (true) {
        cout << "Gimme a number" << endl;
        cin >> x;
        if (x == r) {
            cout << "Success" << i << endl;
            break;
        } else {
            if (x < r) {
                cout << "more!" << endl;
            } else {
                cout << "less!" << endl;
            }
        }
    }
}

bool isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return true;
    }

    return false;
}

string dec2bin(int dec) {
    string bin_str = "";
    while (dec > 0) {
        bin_str += to_string(dec % 2);
        dec /= 2;
    }

    int length = bin_str.length();
    for (int i = 0; i < length / 2; i++) {
        char temp = bin_str[i];
        bin_str[i] = bin_str[length - i - 1];
        bin_str[length - i - 1] = temp;
    }
    return bin_str;
}

string bin2dec(const string& binaryString) {
    int decimal = 0;

    // Convert binary to decimal
    for (size_t i = 0; i < binaryString.length(); ++i) {
        if (binaryString[i] == '1') {
            decimal = decimal * 2 + 1;
        } else {
            decimal *= 2;
        }
    }

    // Convert decimal to string (without using to_string)
    string decimalString;
    while (decimal > 0) {
        char digit = '0' + (decimal % 10);
        decimalString = digit + decimalString;
        decimal /= 10;
    }

    // Special case: input is "0" (binary) or empty string
    if (decimalString.empty()) {
        decimalString = "0";
    }

    return decimalString;
}

int main() {
//    LAB01
//    cout << nwd(2, 4) << endl;
//    cout << nww(2, 4) << endl;
//    cout << silnia_it(4) << endl;
//    cout << silnia_rec(4) << endl;
//    cout << pow(2, 10) << endl;
//    cout << sum(7371) << endl;

//    LAB02
//    calculateTriangle(5,5,5);
//    sieve(40);
//    fibb(10);
//    calculator(5, 5);
}
