#include <iostream>
#include <vector>

std::vector<std::vector<char>> rug(int n, int m);
void like_or_not(int n, int m);

int main() {

  int t, n, m;

  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cin >> n >> m;
    like_or_not(n, m);
    if (i != t - 1)
      std::cout << "\n";
  }

  return 0;
}

std::vector<std::vector<char>> rug(int n, int m) {

  std::vector<std::vector<char>> res(n);
  for (int i = 0; i < n; i++) {
    res[i].resize(m);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> res[i][j];
    }
  }

  return res;
}

void like_or_not(int n, int m) {
  std::vector<std::vector<char>> arr = rug(n, m);
  std::vector<char> name = {'v', 'i', 'k', 'a'};
  int cur = 0;

  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (arr[i][j] == name[cur]) {
        ++cur;
        break;
      }
    }
    if (cur == 4) {
      break;
    }
  }
  if (cur == 4)
    std::cout << "yes";
  else
    std::cout << "no";
}