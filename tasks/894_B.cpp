#include <iostream>
#include <vector>

std::vector<int> input(long unsigned int size);
void original_cons(long unsigned int n);

int main() {

  long unsigned int t, n;

  std::cin >> t;
  for (long unsigned int i = 0; i < t; ++i) {
    std::cin >> n;
    original_cons(n);
    if (i != t - 1)
      std::cout << "\n";
  }

  return 0;
}
std::vector<int> input(long unsigned int size) {
  std::vector<int> res(size);
  for (long unsigned int i = 0; i < size; ++i) {
    std::cin >> res[i];
  }

  return res;
}

void original_cons(long unsigned int n) {

  std::vector<int> b = input(n);
  std::vector<int> res(2 * n);

  res[0] = b[0];
  long unsigned int k = 0;
  for (long unsigned int i = 1; i < n; i++) {
    if (b[i] >= b[i - 1])
      res[i + k] = b[i];
    else {
      res[i + k] = 1 + rand() % (b[i]);
      ++k;
      res[i + k] = b[i];
    }
  }
  std::cout << n + k << "\n";

  for (long unsigned int i = 0; i < n + k; i++) {
    std::cout << res[i] << " ";
  }
}