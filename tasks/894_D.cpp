#include <iostream>
#include <math.h>
#include <vector>

unsigned long long min(unsigned long long kinds);

int main() {

  unsigned long long n, ice_cream_kinds;
  int t;

  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cin >> n;
    ice_cream_kinds = min(n);
    std::cout << ice_cream_kinds;
    if (i != t - 1)
      std::cout << "\n";
  }

  return 0;
}

unsigned long long min(unsigned long long kinds) {

  unsigned long long res = (1 + sqrt(1 + 8 * kinds)) / 2;
  if ((res * res - res) /2 > kinds)
    --res;
  res += kinds - (res * res - res)/2;

  return res;
}