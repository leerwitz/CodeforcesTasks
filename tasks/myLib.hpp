#include <iostream>

long long modular_multiplication(long long a, long long b, long long mod) { return a * b % mod; }

long long pow(long long variable, long long power, long long mod) {
    long long current_multiplier = variable, result = 1;

    while (power != 0) {
        current_multiplier = current_multiplier % mod;
        if (power % 2 == 1) {
            result = modular_multiplication(result, current_multiplier, mod);
            --power;
        }
        current_multiplier = modular_multiplication(current_multiplier, current_multiplier, mod);
        power /= 2;
    }

    return result % mod;
}

long long get_bit_degree(long long value) {
    long long t = 1 << 30, result = 30;
    while (value < t) {
        --result;
        t >>= 1;
    }

    return result;
}

long long pow(long long variable, long long power) {
    long long current_multiplier = variable, result = 1;

    while (power != 0) {
        current_multiplier = current_multiplier;
        if (power % 2 == 1) {
            result *= current_multiplier;
            --power;
        }
        current_multiplier *= current_multiplier;
        power /= 2;
    }

    return result;
}

long long greatest_common_divisor(long long a, long long b, long long &coefficient_on_a, long long &coefficient_on_b) {
    if (a == 0) {
        coefficient_on_a = 0;
        coefficient_on_b = 1;
        return b;
    } else {
        long long new_coefficient_on_a = 0, new_coefficient_on_b = 0;
        long long res = greatest_common_divisor(b % a, a, new_coefficient_on_a, new_coefficient_on_b);
        coefficient_on_b = new_coefficient_on_a;
        coefficient_on_a = new_coefficient_on_b - b / a * new_coefficient_on_a;

        return res;
    }
}

long long extended_Euclidean_algorithm(long long a, long long modulus_value) {
    long long coefficient_on_a, coefficient_on_b;
    if (greatest_common_divisor(a, modulus_value, coefficient_on_a, coefficient_on_b) != 1) {
        return 0;
    } else {
        coefficient_on_a = (coefficient_on_a % modulus_value + modulus_value) % modulus_value;
    }

    return coefficient_on_a;
}

// long long reverse_element(long long element, long long module){
//     long long coef_element = 0, coef_module = 0;
//     long long g = greatest_common_divisor(element, module, coef_element, coef_module);
//     coef_element = (coef_element % module + module) % module;
//     return coef_element;
// }
