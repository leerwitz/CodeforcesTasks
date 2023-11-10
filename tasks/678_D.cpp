#include <iostream>
#include <vector>

long long int pow(long long int variable, long long power);
long long int binary_function(long long int const_A, long long int const_B, long long int variable_x, long long int power_n);
std::vector<std::vector<long long int>> multiplyed_matrix_coefficient(std::vector<std::vector<long long int>> left_matrix_coefficient,
                                                                      std::vector<std::vector<long long int>> right_matrix_coefficient);
long long int binary_matrix_coefficient_multiplayed(long long int const_A, long long int const_B, long long int variable_x, long long int power_n);
long long int modular_multiplication(long long int a, long long int b);
long long int modular_addition(long long int a, long long int b);

long long int pow(long long int variable, long long power) {
    long long int current_multiplier = variable, result = 1;

    while (power != 0) {
        current_multiplier = current_multiplier % 1000000007;
        if (power % 2 == 1) {
            result = modular_multiplication(result, current_multiplier);
            --power;
        }
        current_multiplier = modular_multiplication(current_multiplier, current_multiplier);
        power /= 2;
    }

    return result % 1000000007;
}

std::vector<std::vector<long long int>> multiplyed_matrix_coefficient(std::vector<std::vector<long long int>> left_matrix_coefficient,
                                                                      std::vector<std::vector<long long int>> right_matrix_coefficient) {
    std::vector<std::vector<long long int>> result(left_matrix_coefficient.size());
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t k = 0; k < right_matrix_coefficient.size(); ++k) {
            long long int new_element = 0, current_addition;
            for (size_t j = 0; j < right_matrix_coefficient[0].size(); ++j) {
                current_addition = modular_multiplication(left_matrix_coefficient[i][j], right_matrix_coefficient[j][k]);
                new_element = modular_addition(new_element, current_addition);
            }

            result[i].push_back(new_element);
        }
    }

    return result;
}

long long int binary_function(long long int const_A, long long int const_B, long long int variable_x, long long int power_n) {
    long long int result_A = 0, result_B = 0, result;
    long long int const_C = pow(const_A, power_n), current_B = power_n, current_x = const_C;

    if (const_A != 1) current_B = (const_C - 1);

    while (variable_x != 0 || const_B != 0) {
        if (variable_x % 2 == 1) {
            result_A = modular_addition(result_A, current_x);
            --variable_x;
        }

        current_x = modular_addition(current_x, current_x);
        variable_x /= 2;

        if (const_B % 2 == 1) {
            result_B = modular_addition(result_B, current_B);
            --const_B;
        }
        current_B = modular_addition(current_B, current_B);
        const_B /= 2;
    }

    if (const_A != 1)
        result = modular_addition(result_A, result_B / (const_A - 1));
    else
        result = modular_addition(result_A, result_B);

    return result;
}

long long int binary_matrix_coefficient_multiplayed(long long int const_A, long long int const_B, long long int variable_x, long long int power_n) {
    std::vector<std::vector<long long int>> matrix_coefficient(2);
    matrix_coefficient[0].push_back(const_A);
    matrix_coefficient[0].push_back(0);
    matrix_coefficient[1].push_back(const_B);
    matrix_coefficient[1].push_back(1);

    std::vector<std::vector<long long int>> answer(1);
    answer[0].push_back(variable_x);
    answer[0].push_back(1);

    while (power_n != 0) {
        if (power_n % 2 == 1) {
            answer = multiplyed_matrix_coefficient(answer, matrix_coefficient);
            --power_n;
        }

        matrix_coefficient = multiplyed_matrix_coefficient(matrix_coefficient, matrix_coefficient);
        power_n /= 2;
    }

    return answer[0][0] % 1000000007;
}

long long int modular_multiplication(long long int a, long long int b) { return a * b % 1000000007; }

long long int modular_addition(long long int a, long long int b) {
    if (a + b >= 1000000007) return a + b - 1000000007;
    return a + b;
}

int main() {
    long long int const_A, const_B, power_n, variable_x;

    std::cin >> const_A >> const_B >> power_n >> variable_x;

    std::cout << binary_matrix_coefficient_multiplayed(const_A, const_B, variable_x, power_n);

    return 0;
}