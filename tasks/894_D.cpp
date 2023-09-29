#include <iostream>
#include <math.h>
#include <vector>

unsigned long long min_number_of_kinds(unsigned long long kinds_needed);

unsigned long long min_number_of_kinds(unsigned long long kinds_needed) {

  unsigned long long res = (1 + sqrt(1 + 8 * kinds_needed)) / 2;
  if ((res * res - res) /2 > kinds_needed)
    --res;
  if(kinds_needed - (res * res - res)/2 >= res )
  ++res;
  res += kinds_needed - (res * res - res)/2;

  return res;
}

int main() {

  unsigned long long kinds_needed, ice_cream_kinds;
  int number_of_inputs;

  std::cin >> number_of_inputs;
  for (int i = 0; i < number_of_inputs; ++i) {
    std::cin >> kinds_needed;
    ice_cream_kinds = min_number_of_kinds(kinds_needed);
    std::cout << ice_cream_kinds;
    if (i != number_of_inputs - 1)
      std::cout << "\n";
  }

  return 0;
}

