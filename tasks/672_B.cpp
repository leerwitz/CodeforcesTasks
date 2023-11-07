#include <math.h>

#include <iostream>
#include <vector>

long long int binary_find_degree(long long int value, long long int min_degree, long long int max_degree, std::vector<long long int> &array_degree);
long long int bit_degree(long long int value);
long long int Task_Answer2(std::vector<long long int> &arr, std::vector<long long int> &array_degree);

long long int binary_find_degree(long long int value, long long int min_degree, long long int max_degree, std::vector<long long int> &array_degree) {
    if (value == 0) return -1;
    long long int result = (max_degree + min_degree) / 2;
    if (array_degree[result] > value)
        result = binary_find_degree(value, min_degree, result, array_degree);
    else if (array_degree[result + 1] <= value)
        result = binary_find_degree(value, result, max_degree, array_degree);
    return result;
}

long long int bit_degree(long long int value) {
    long long int t = 1 << 30, result = 30;
    while (value < t) {
        --result;
        t >>= 1;
    }

    return result;
}

long long int Task_Answer2(std::vector<long long int> &arr, std::vector<long long int> &array_degree) {
    long long int result = 0, size = 0;
    std::vector<long long int> arr_max_degree = std::vector<long long int>(34, 0);
    for (size_t i = 0; i < arr.size(); ++i) {
        //++arr_max_degree[bit_degree(arr[i])];
        ++arr_max_degree[binary_find_degree(arr[i], 0, 30, array_degree)];
    }

    for (size_t i = 0; i < arr_max_degree.size(); ++i) {
        result += (arr_max_degree[i] * (arr_max_degree[i] - 1)) / 2;
    }

    return result;
}

int main() {
    size_t number_of_inputs, ArraySize, degree_of_2 = 1;
    std::vector<long long int> array;
    std::cin >> number_of_inputs;
    std::vector<long long int> array_degree = std::vector<long long int>(34);

    for (size_t i = 0; i < array_degree.size(); ++i) {
        array_degree[i] = degree_of_2;
        degree_of_2 *= 2;
    }

    for (size_t i = 0; i < number_of_inputs; ++i) {
        std::cin >> ArraySize;
        array.resize(ArraySize);
        for (size_t j = 0; j < ArraySize; ++j) {
            std::cin >> array[j];
        }

        std::cout << Task_Answer2(array, array_degree) << '\n';
    }

    return 0;
}