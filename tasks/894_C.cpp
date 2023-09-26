#include <iostream>
#include <vector>

std::vector<int> input(int size);
void simmetry(int n);

int main() {

  int t, n;

  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cin >> n;
    simmetry(n);
    if (i != t - 1)
      std::cout << "\n";
  }

  return 0;
}

std::vector<int> input(int size) {
  std::vector<int> res(size);
  for (int i = 0; i < size; ++i) {
    std::cin >> res[i];
  }

  return res;
}

void simmetry(int n) {
  std::vector<int> fence = input(n);
  int k = 1, j = 0;
  if (fence[0] == n) {
    for (int i = n - 1; i > +0; --i) {
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