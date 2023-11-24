//
// Created by aleks on 13.11.2023.
//

#include "silnia.h"

int silnia_iterate(int power) {
    int result = 1;
    if (power > 1) {
        for (int i = 2; i <= power; i++) {
            result *= i;
        }
    }

    return power > 1 ? result : 1;
}

int silnia_rec(int power) {
    if (power > 1) {
        return power * silnia_rec(power - 1);
    }
    return 1;
}
