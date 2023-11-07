#include <math.h>

#include <iostream>
#include <vector>
int max_addition(int current_rating, int killjoy_rating);
int max_subtraction(int current_rating, int killjoy_rating);
int GetNumberOfSteps(std::vector<int> &array_rating_healthy, std::vector<int> &array_rating_infected, int killjoy_rating);
void GetArrayHealthyAccounts(std::vector<int> &array_rating_healthy, std::vector<int> &array_rating_infected, int killjoy_rating, int &amount_rating_infected, int old_size);

int max_addition(int current_rating, int killjoy_rating) { return 4000 - (killjoy_rating - current_rating); }

int max_subtraction(int current_rating, int killjoy_rating) { return -4000 - (killjoy_rating - current_rating); }

void GetArrayHealthyAccounts(std::vector<int> &array_rating_healthy, std::vector<int> &array_rating_infected, int killjoy_rating, int &amount_rating_infected, int old_size) {
    std::vector<int> result = std::vector<int>();
    size_t j = 0;
    int amount_rating_healthy = 0;
    for (size_t i = 0; i < array_rating_healthy.size(); i++) {
        amount_rating_healthy += array_rating_healthy[i];
    }

    if (amount_rating_healthy == 0) array_rating_healthy.clear();
}

int GetNumberOfSteps(std::vector<int> &array_rating_healthy, std::vector<int> &array_rating_infected, int killjoy_rating) {
    int result, amount_rating_infected = 0;
    for (size_t i = 0; i < array_rating_healthy.size(); ++i) {
        if (array_rating_healthy[i] == 0) {
            array_rating_infected.push_back(killjoy_rating);
            amount_rating_infected += killjoy_rating;
            array_rating_healthy.erase(array_rating_healthy.begin() + i);
            --i;
        }
    }

    if (array_rating_healthy.size() == 0)
        result = 0;
    else if (array_rating_infected.size() > 0)
        result = 1;
    else {
        GetArrayHealthyAccounts(array_rating_healthy, array_rating_infected, killjoy_rating, amount_rating_infected, array_rating_infected.size());

        if (array_rating_healthy.size() == 0)
            result = 1;
        else
            result = 2;
    }

    return result;
}

int main() {
    size_t number_of_inputs, ArraySize, killjoy_rating;
    std::vector<int> array;
    std::cin >> number_of_inputs;
    std::vector<int> array_rating_healthy = std::vector<int>();
    std::vector<int> array_rating_infected = std::vector<int>();
    for (size_t i = 0; i < number_of_inputs; ++i) {
        std::cin >> ArraySize >> killjoy_rating;
        array_rating_healthy.resize(ArraySize);
        for (size_t j = 0; j < array_rating_healthy.size(); ++j) {
            std::cin >> array_rating_healthy[j];
            array_rating_healthy[j] = killjoy_rating - array_rating_healthy[j];
        }
        std::cout << GetNumberOfSteps(array_rating_healthy, array_rating_infected, killjoy_rating) << '\n';

        array_rating_infected.clear();
    }

    return 0;
}