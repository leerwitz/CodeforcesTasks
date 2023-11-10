#include <ctime>
#include <unordered_map>
#include "Hashtable.hpp"

void CompareGet(std::unordered_map<int, double> StdHashTable, Hashtable<int, double> MyHashTable, size_t number_of_inputs);
void CompareInput(std::unordered_map<int, double> &StdHashTable, Hashtable<int, double> &MyHashTable, size_t number_of_inputs);


template <typename Key, typename Value>
size_t Hashtable<Key, Value>::HashFunction(Key x) {
    int s = 1, result = 0;
    for (int i = 0; i < 3; ++i) {
        result += s * static_cast<int>(x + i, i);
        s *= s + 1;
    }

    return static_cast<size_t>(result);
}

void CompareInput(std::unordered_map<int, double> &StdHashTable, Hashtable<int, double> &MyHashTable, size_t number_of_inputs) {
    unsigned int Mystart_time = std::clock();
    for (size_t i = 0; i < number_of_inputs; ++i) {
        MyHashTable.inputValue(i, static_cast<double>(rand() / RAND_MAX * number_of_inputs));
    }
    unsigned int Myend_time = std::clock();
    unsigned int MyTime = Myend_time - Mystart_time;

    unsigned int Stdstart_time = std::clock();
    for (size_t i = 0; i < number_of_inputs; ++i) {
        StdHashTable.insert({i, static_cast<double>(rand() / RAND_MAX * number_of_inputs)});
    }
    unsigned int Stdend_time = std::clock();
    unsigned int StdTime = Stdend_time - Stdstart_time;
    std::cout << "My Hashtable input time for " << number_of_inputs << ": " << MyTime << '\n';
    std::cout << "Std Hashtable input time for " << number_of_inputs << ": " << StdTime;
}

void CompareGet(std::unordered_map<int, double> StdHashTable, Hashtable<int, double> MyHashTable, size_t number_of_inputs) {
    std::clock_t Mystart_time = std::clock();
    for (size_t i = 0; i < number_of_inputs; ++i) {
        MyHashTable.GetValue(i);
    }
    std::clock_t Myend_time = std::clock();
    std::clock_t Mytime = Myend_time - Mystart_time;

    std::clock_t Stdstart_time = std::clock();
    for (size_t i = 0; i < number_of_inputs; ++i) {
        StdHashTable[i];
    }
    std::clock_t Stdend_time = std::clock();
    std::clock_t Stdtime = Stdend_time - Stdstart_time;

    std::cout << "My Hashtable get time for " << number_of_inputs << ": " << Mytime << '\n';
    std::cout << "Std Hashtable get time for " << number_of_inputs << ": " << Stdtime << '\n';
}

int main() {
    Hashtable<int, double> MyHashTable = Hashtable<int, double>();
    std::unordered_map<int, double> StdHashTable = std::unordered_map<int, double>();
    CompareInput(StdHashTable, MyHashTable, 50000);
    std::cout << '\n';
    CompareGet(StdHashTable, MyHashTable, 50000);

    return 0;
}
