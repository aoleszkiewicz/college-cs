#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
//#include <silnia.h>

void countCharacters(char *str) {
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = str[i];

        if (!isspace(currentChar)) {
            counter++;
        }
    }

    printf("Characters: %d\n", counter);
}

void calculateTax(int hoursWorked) {
    const int payPerHour = 40;
    const int payPerOverWorkHour = payPerHour * 1.5;

    const int hoursPerWeek = 8 * 5;

    float income = 0;

    if (hoursWorked) {
        income += payPerHour * hoursPerWeek;

        if (hoursWorked > hoursPerWeek) {
            int overHours = hoursWorked - hoursPerWeek;
            income += payPerOverWorkHour * overHours;
        }

        if (income > 0) {
            printf("15 percent tax: %f\n", income * 0.15);
        }
        if (income > 1200) {
            printf("20 percent tax: %f\n", income * 0.20);
        }
        if (income > 1800) {
            printf("25 percent tax: %f\n", income * 0.25);
        }
    }
}

// Sprawozdanie 4
//void countCharacters(char *str) {
//    int counter = 0;
//
//    for (int i = 0; str[i] != '\0'; i++) {
//        char currentChar = str[i];
//
//        if (!isspace(currentChar)) {
//            counter++;
//        }
//    }
//
//    putchar(counter);
//}
//
void calculateTax(int hoursWorked) {
    const int payPerHour = 40;
    const int payPerOverWorkHour = payPerHour * 1.5;

    const int hoursPerWeek = 8 * 5;

    float income = 0;

    if (hoursWorked) {
        income += payPerHour * hoursPerWeek;

        if (hoursWorked > hoursPerWeek) {
            int overHours = hoursWorked - hoursPerWeek;
            income += payPerOverWorkHour * overHours;
        }

        double brutto, tax;

        if (income > 0) {
            brutto = income * 0.85;
            tax = income * 0.15;
            printf("NETTO: %d, BRUTTO: %d, PODATEK %f\n", income, brutto, tax);
        }
        if (income > 1200) {
            brutto = income * 0.80;
            tax = income * 0.2;
            printf("NETTO: %d, BRUTTO: %d, PODATEK %f\n", income, brutto, tax);
        }
        if (income > 1800) {
            brutto = income * 0.75;
            tax = income * 0.25;
            printf("NETTO: %d, BRUTTO: %d, PODATEK %f\n", income, brutto, tax);
        }
    }
}

// Sprawozdanie 5
double min(int x, int y) {
    return x > y ? x : y;
}

int main() {
//  countCharacters("test     bb");
//    calculateTax(60);
//    int silnia_z_5 = silnia_iterate(5);
//    printf("silnia: %d", silnia_z_5);
//int silnia_z_5_rec = silnia_rec(5);
//printf("silnia: %d", silnia_z_5_rec);
//    countCharacters("btkj    nwklefnlwnfw");
//    countCharacters("test test test");
//    calculateTax(40);
    calculateTax(40);
    return 0;
}