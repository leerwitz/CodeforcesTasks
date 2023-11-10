#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void swap(char &a, char &b);
void substring_reversal(std::string &string, int first, int last, std::vector<std::vector<int>> operation_description, int interval_index);
std::vector<std::vector<int>> getMatrix_of_operations(int number_of_operations, std::vector<int> array_l, std::vector<int> array_r);

template <typename type>
std::vector<type> input_array(int size) {
    std::vector<type> res = std::vector<type>(size);
    for (int i = 0; i < size; i++) {
        std::cin >> res[i];
    }

    return res;
}

void swap(char &a, char &b) {
    char c = a;
    a = b;
    b = c;
}

std::vector<std::vector<int>> getMatrix_of_operations(int number_of_operations, std::vector<int> array_l, std::vector<int> array_r) {
    std::vector<std::vector<int>> res = std::vector<std::vector<int>>(array_l.size());
    int current_operation;
    for (int i = 0; i < number_of_operations; ++i) {
        std::cin >> current_operation;
        for (size_t j = 0; j < res.size(); ++j) {
            if (current_operation >= array_l[j] && current_operation <= array_r[j]) {
                if (current_operation > (array_l[j] + array_r[j]) / 2)
                    res[j].push_back(array_l[j] + array_r[j] - current_operation);
                else
                    res[j].push_back(current_operation);
                break;
            }
        }
    }

    for (size_t i = 0; i < res.size(); i++) {
        std::sort(begin(res[i]), end(res[i]));
    }

    return res;
}

void substring_reversal(std::string &string, int first, int last, std::vector<std::vector<int>> operation_description, int interval_index) {
    int current_operation, end_index, begin_index;
    for (size_t i = 0; i < operation_description[interval_index].size(); i += 2) {
        if (i != operation_description[interval_index].size() - 1)
            end_index = operation_description[interval_index][i + 1] - 1;
        else
            end_index = (last + first) / 2 + 1;
        begin_index = operation_description[interval_index][i] - 1;
        for (int j = begin_index; j < end_index; ++j) {
            swap(string[j], string[last - j + first]);
        }
    }
}

int main() {
    int number_of_inputs, array_size, number_of_operations, string_size;

    std::cin >> number_of_inputs;
    for (int i = 0; i < number_of_inputs; i++) {
        std::cin >> string_size >> array_size;
        std::string string;
        std::cin >> string;
        std::vector<int> array_l = input_array<int>(array_size);
        std::vector<int> array_r = input_array<int>(array_size);
        std::cin >> number_of_operations;
        std::vector<std::vector<int>> operation_description = getMatrix_of_operations(number_of_operations, array_l, array_r);
        for (int j = 0; j < array_size; ++j) {
            substring_reversal(string, array_l[j] - 1, array_r[j] - 1, operation_description, j);
        }

        std::cout << string << '\n';
    }

    return 0;
}