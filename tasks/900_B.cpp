#include <math.h>

#include <iostream>
#include <vector>

std::vector<int> input_vector(long unsigned int size_of_vector);

std::vector<int> input_vector(long unsigned int size_of_vector) {
    std::vector<int> res = std::vector<int>(size_of_vector);
    res[0] = 1;
    res[1] = 3;
    for (long unsigned int i = 2; i < size_of_vector; i++) {
        res[i] = res[i - 1] + 1;
        if (3 * res[i] % (res[i - 1] + res[i - 1]) == 0) ++res[i];
    }

    return res;
}

int main() {
    long unsigned int size_of_vector, number_of_inputs;

    std::cin >> number_of_inputs;
    for (long unsigned int i = 0; i < number_of_inputs; i++) {
        std::cin >> size_of_vector;
        std::vector<int> arr = input_vector(size_of_vector);
        for (long unsigned int j = 0; j < size_of_vector; j++) {
            std::cout << arr[j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}