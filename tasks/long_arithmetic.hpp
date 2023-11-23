#include <iostream>
#include <vector>

typedef std::vector<long long> lnum;

void print_long_number(lnum number);
lnum get_vector_from_number_string(std::string str);
std::string get_number_string_from_string(std::string str);
size_t get_numerical_order(lnum number);
lnum get_lnum_from_string(std::string &str);
lnum long_add(lnum &a, lnum &b);
lnum long_sub(lnum &a, lnum &b);
lnum mult_long_short(lnum &lnumber, long long b);
lnum mult_long(lnum a, lnum b);
bool cmp_long(lnum a, lnum b);
std::string get_string_from_lnum(lnum number);

const long long base = 1000 * 1000 * 1000;

void print_long_number(lnum number) {
    printf("%lld", number.empty() ? 0 : number.back());
    for (long long i = static_cast<long long>(number.size()) - 2; i >= 0; --i) {
        printf("%09lld", number[i]);
    }
}

lnum get_vector_from_number_string(std::string str) {
    lnum res = lnum();
    for (long long i = static_cast<long long>(str.size()); i > 0; i -= 9) {
        if (i < 9)
            res.push_back(atoi(str.substr(0, i).c_str()));
        else
            res.push_back(atoi(str.substr(i - 9, 9).c_str()));
    }
    return res;
}

std::string get_number_string_from_string(std::string str) {
    std::string number_str = "";
    for (char ch : str) {
        if (static_cast<long long>(ch) < 10) number_str += "0";
        if (static_cast<long long>(ch) < 100) number_str += "0";
        number_str += std::to_string(static_cast<long long>(ch));
    }
    return number_str;
}

size_t get_numerical_order(lnum number) { return std::to_string(number.back()).size() + (number.size() - 1) * 9; }

lnum get_lnum_from_string(std::string &str) {
    str = get_number_string_from_string(str);
    return get_vector_from_number_string(str);
}

lnum long_add(lnum &a, lnum &b) {
    long long carry = 0;
    for (size_t i = 0; i < std::max(a.size(), b.size()) || carry; ++i) {
        if (i > a.size()) a.push_back(0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry) a[i] -= base;
    }
    return a;
}

lnum long_sub(lnum &a, lnum &b) {
    long long carry = 0;
    for (size_t i = 0; i < std::max(a.size(), b.size()); ++i) {
        if (a.size() < b.size() || (a.size() == b.size() && a.back() - b.back() < 0)) {
            long_sub(b, a);
            b.back() *= -1;
            a = b;
            return a;
        }

        if (i > a.size()) a.push_back(0);
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry && i == std::max(a.size(), b.size()) - 1) a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    return a;
}

lnum mult_long_short(lnum &lnumber, long long b) {
    long long carry = 0;
    for (size_t i = 0; i < lnumber.size() || carry; ++i) {
        long long cur = carry + lnumber[i] * 1ll * b;
        lnumber[i] = static_cast<long long>(cur % base);
        carry = static_cast<long long>(cur / base);
    }
    while (lnumber.size() > 1 && lnumber.back() == 0) lnumber.pop_back();
    return lnumber;
}

lnum mult_long(lnum a, lnum b) {
    lnum res(a.size() + b.size());

    for (size_t i = 0; i < a.size(); ++i) {
        for (long long j = 0, carry = 0; j < static_cast<long long>(b.size()) || carry; ++j) {
            long long cur = res[i + j] + a[i] * 1ll * (j < static_cast<long long>(b.size()) ? b[j] : 0);
            carry = static_cast<long long>(cur / base);
            res[i + j] = static_cast<long long>(cur % base);
        }
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

bool cmp_long(lnum a, lnum b) {
    if (a.size() == b.size()) {
        long long i = a.size() - 1;
        while (a[i] == b[i]) --i;
        return a[i] > b[i];
    } else
        return a.size() > b.size();
}

std::string get_string_from_lnum(lnum number) {
    std::string number_string = "";
    std::string res = "";
    std::string cur;
    size_t string_lenght = get_numerical_order(number);

    for (int i = number.size() - 1; i >= 0; --i) {
        cur = std::to_string(number[i]);
        for (long long j = 0; j < 9 - static_cast<long long>(cur.size()) && i != static_cast<int>(number.size()) - 1 && cur.size() < 10; ++j) number_string += '0';
        number_string += cur;
    }

    for (int i = 0; i < static_cast<int>(string_lenght); i += 3) {
        if (i == 0) {
            res += static_cast<char>(atoi(number_string.substr(i, 3 - (3 - (string_lenght % 3)) % 3).c_str()));
            i -= (3 - (string_lenght % 3)) % 3;
        } else {
            res += static_cast<char>(atoi(number_string.substr(i, 3).c_str()));
        }
    }

    return res;
}