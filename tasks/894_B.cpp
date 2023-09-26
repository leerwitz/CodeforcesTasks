#include <iostream>
#include <vector>

std::vector<int> input(int size);
void original_cons(int n);

int main() {

  int t, n;

  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cin >> n;
    original_cons(n);
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

void original_cons(int n) {

  std::vector<int> b = input(n);
  std::vector<int> res(2 * n);

  res[0] = b[0];
  int k = 0;
  for (int i = 1; i < n; i++) {
    if (b[i] >= b[i - 1])
      res[i + k] = b[i];
    else {
      res[i + k] = 1 + rand() % (b[i]);
      ++k;
      res[i + k] = b[i];
    }
  }
  std::cout << n + k << "\n";

  for (int i = 0; i < n + k; i++) {
    std::cout << res[i] << " ";
  }
}