#include <iostream>
#include <vector>

std::vector<long unsigned int> input_fence(long unsigned int size_fence);
bool is_simmetrycal(long unsigned int size_fence);

bool is_simmetrycal(long unsigned int size_fence) {
    std::vector<long unsigned int> fence = input_fence(size_fence);
    long unsigned int k = 1, j = 0;
    bool res;

    if (fence[0] == size_fence) {
        for (long unsigned int i = size_fence - 1; i > +0; --i) {
            while (fence[i] >= k) {
                if (fence[j] != i + 1) {
                    res = false;
                    return res;
                }
                ++j;
                ++k;
            }
        }
        res = true;
    } else {
        res = false;
    }

    return res;
}

std::vector<long unsigned int> input_fence(long unsigned int size_fence) {
    std::vector<long unsigned int> res(size_fence);
    for (long unsigned int i = 0; i < size_fence; ++i) {
        std::cin >> res[i];
    }

    return res;
}

int main() {
    long unsigned int number_of_inputs, size_fence;

    std::cin >> number_of_inputs;
    for (long unsigned int i = 0; i < number_of_inputs; ++i) {
        std::cin >> size_fence;
        if (is_simmetrycal(size_fence))
            std::cout << "yes";
        else
            std::cout << "no";
        if (i != number_of_inputs - 1) std::cout << "\n";
    }

    return 0;
}
