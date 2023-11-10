#include <math.h>

#include <iostream>
#include <vector>

bool isHaveDifferentNumbers(long long unsigned int max, long long unsigned int number_different_numbers, long long unsigned int needed_amount);

bool isHaveDifferentNumbers(long long unsigned int max, long long unsigned int number_different_numbers, long long unsigned int needed_amount) {
    long long unsigned int min_amount, max_amount;
    bool res = false;

    min_amount = (1 + number_different_numbers) * number_different_numbers / 2;
    max_amount = min_amount + (max - number_different_numbers) * number_different_numbers;
    if (needed_amount <= max_amount && needed_amount >= min_amount) res = true;

    return res;
}

int main() {
    long long unsigned int needed_amount, number_of_inputs, number_different_numbers, max;

    std::cin >> number_of_inputs;
    for (long long unsigned int i = 0; i < number_of_inputs; i++) {
        std::cin >> max >> number_different_numbers >> needed_amount;
        if (isHaveDifferentNumbers(max, number_different_numbers, needed_amount))
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }

    return 0;
}