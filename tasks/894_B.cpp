#include <iostream>
#include <vector>

std::vector<int> input(long unsigned int size);
std::vector<int> possible_sequence(long unsigned int size_sequence);

std::vector<int> input(long unsigned int size) {
    std::vector<int> res(size);
    for (long unsigned int i = 0; i < size; ++i) {
        std::cin >> res[i];
    }

    return res;
}

std::vector<int> possible_sequence(long unsigned int size_sequence) {
    std::vector<int> b = input(size_sequence);
    std::vector<int> res(2 * size_sequence);

    res[0] = b[0];
    long unsigned int k = 0;
    for (long unsigned int i = 1; i < size_sequence; i++) {
        if (b[i] >= b[i - 1])
            res[i + k] = b[i];
        else {
            res[i + k] = 1 + rand() % (b[i]);
            ++k;
            res[i + k] = b[i];
        }
    }
    res.resize(size_sequence + k);

    return res;
}

int main() {
    long unsigned int number_of_inputs, n;
    std::vector<int> original_sequence;
    std::cin >> number_of_inputs;
    for (long unsigned int i = 0; i < number_of_inputs; ++i) {
        std::cin >> n;
        original_sequence = possible_sequence(n);
        std::cout << original_sequence.size() << "\n";
        for (long unsigned int j = 0; j < original_sequence.size(); j++) {
            std::cout << original_sequence[j] << " ";
        }
        if (i != number_of_inputs - 1) std::cout << "\n";
    }

    return 0;
}
