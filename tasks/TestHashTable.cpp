#include <iostream>
#include <string>

#include "Hashtable.hpp"

template <typename Key, typename Value>
size_t Hashtable<Key, Value>::HashFunction(Key x) {
    int s = 1, result = 0;
    for (int i = 0; i < 3; ++i) {
        result += s * (int)pow(x + i, i);
        s *= s + 1;
    }

    return (size_t)abs(result);
}

int main() {
    Hashtable<int, std::string> map = Hashtable<int, std::string>(2);
    map.inputValue(3, "ass");
    map.inputValue(34, "wee");
    map.inputValue(77, "can");

    if (map.HaveValue(3, "ass")) {
        std::cout << map.GetValue(3) << " " << map.GetValue(34) << " " << map.GetValue(77);
    }

    return 0;
}