#include <iostream>
#include <vector>

std::vector<long unsigned int> input(long unsigned int size);
void simmetry(long unsigned int n);

int main() {

  long unsigned int t, n;

  std::cin >> t;
  for (long unsigned int i = 0; i < t; ++i) {
    std::cin >> n;
    simmetry(n);
    if (i != t - 1)
      std::cout << "\n";
  }

  return 0;
}

std::vector<long unsigned int> input(long unsigned int size) {
  std::vector<long unsigned int> res(size);
  for (long unsigned int i = 0; i < size; ++i) {
    std::cin >> res[i];
  }

  return res;
}

void simmetry(long unsigned int n) {
  std::vector<long unsigned int> fence = input(n);
  long unsigned int k = 1, j = 0;
  if (fence[0] == n) {
    for (long unsigned int i = n - 1; i > +0; --i) {
      while (fence[i] >= k) {
        if (fence[j] != i + 1) {
          std::cout << "no";
          return;
        }
        ++j;
        ++k;
      }
    }
    std::cout << "yes";
  } else {
    std::cout << "no";
  }
}