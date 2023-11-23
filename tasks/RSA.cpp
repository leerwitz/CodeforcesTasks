#include <ctime>
#include <iostream>

#include "long_arithmetic.hpp"
#include "myLib.hpp"

class RSA {
   private:
    const size_t MAX = 46000;
    const size_t MIN = 31700;
    std::pair<size_t, size_t> private_key;
    std::pair<size_t, size_t> public_key;
    size_t euler_func;
    size_t get_random_prime_number(size_t max, size_t min) {
        size_t res = min + 2;
        while (!is_prime_number(res, min)) {
            res = min + static_cast<size_t>(rand()) % (max - min);
        }
        return res;
    }

    bool is_prime_number(size_t number, size_t min) {
        if (number < min) {
            return false;
        } else {
            for (size_t i = 2; i * i <= number; ++i) {
                if (number % i == 0) return false;
            }
        }
        return true;
    }

    size_t get_prime_number_ferma(size_t max) {
        size_t max_degree = get_bit_degree(get_bit_degree(max - 1));
        size_t result = static_cast<size_t>(pow(2, pow(2, max_degree))) + 1;
        long long coef_a, coef_b;

        for (size_t i = max_degree; i > 0; --i) {
            if (greatest_common_divisor(result, max, coef_a, coef_b) == 1) {
                return result;
            }
            if (i > 0) result >>= pow(2, i - 1);
            ++result;
        }

        result = get_random_prime_number(max, 1);

        return result;
    }

    void create_keys() {
        size_t rand_prime_number_1, rand_prime_number_2, public_exp, private_exp;

        rand_prime_number_1 = get_random_prime_number(MAX, MIN);
        rand_prime_number_2 = get_random_prime_number(MAX, MIN);
        this->private_key.second = rand_prime_number_1 * rand_prime_number_2;
        this->public_key.second = this->private_key.second;
        this->euler_func = (rand_prime_number_1 - 1) * (rand_prime_number_2 - 1);
        public_exp = get_prime_number_ferma(this->euler_func);
        private_exp = extended_Euclidean_algorithm(public_exp, this->euler_func);
        this->public_key.first = public_exp;
        this->private_key.first = private_exp;
    }

   public:
    RSA() { create_keys(); };

    ~RSA(){};

    std::pair<size_t, size_t> get_public_key() { return this->public_key; }

    lnum message_encryption(std::string &message) {
        lnum number = get_lnum_from_string(message);
        for (int i = 0; i < static_cast<int>(number.size()); ++i) {
            number[i] = pow(static_cast<long long>(number[i]), this->public_key.first, this->public_key.second);
        }
        message = get_string_from_lnum(number);

        return number;
    }

    lnum message_encryption(std::string &message, std::pair<size_t, size_t> other_public_key) {
        lnum number = get_lnum_from_string(message);
        for (int i = 0; i < static_cast<int>(number.size()); ++i) {
            number[i] = pow(static_cast<long long>(number[i]), other_public_key.first, other_public_key.second);
        }
        message = get_string_from_lnum(number);

        return number;
    }

    std::string message_decryption(lnum &number) {
        std::string message;
        for (int i = 0; i < static_cast<int>(number.size()); ++i) {
            number[i] = pow(static_cast<long long>(number[i]), this->private_key.first, this->private_key.second);
        }
        message = get_string_from_lnum(number);

        return message;
    }
};

int main() {
    srand(time(NULL));

    RSA user = RSA();
    std::pair<size_t, size_t> pub_key = user.get_public_key();
    std::cout << pub_key.first << " " << pub_key.second << '\n';
    std::string message = "hello how are you?";
    lnum cipher = user.message_encryption(message);
    std::cout << message << '\n';
    message = user.message_decryption(cipher);
    std::cout << message << '\n';

    return 0;
}