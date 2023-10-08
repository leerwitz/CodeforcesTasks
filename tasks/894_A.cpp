#include <iostream>
#include <vector>

std::vector<std::vector<char>> rug(long unsigned int length,
                                   long unsigned int width);
bool is_liked_rug(long unsigned int length, long unsigned int width);

std::vector<std::vector<char>> rug(long unsigned int length,
                                   long unsigned int width) {

  std::vector<std::vector<char>> res(length);
  for (long unsigned int i = 0; i < length; i++) {
    res[i].resize(width);
  }
  for (long unsigned int i = 0; i < length; ++i) {
    for (long unsigned int j = 0; j < width; ++j) {
      std::cin >> res[i][j];
    }
  }

  return res;
}

bool is_liked_rug(long unsigned int length, long unsigned int width) {
  std::vector<std::vector<char>> arr = rug(length, width);
  std::vector<char> name = {'v', 'i', 'k', 'a'};
  long unsigned int cur = 0;
  bool res;

  for (long unsigned int j = 0; j < width; ++j) {
    for (long unsigned int i = 0; i < length; ++i) {
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
    res = true;
  else
    res = false;
  return res;
}

int main() {

  long unsigned int number_of_inputs, length, width;

  std::cin >> number_of_inputs;
  for (long unsigned int i = 0; i < number_of_inputs; ++i) {
    std::cin >> length >> width;
    if (is_liked_rug(length, width))
      std::cout << "yes";
    else
      std::cout << "no";
    if (i != number_of_inputs - 1)
      std::cout << '\n';
  }

  return 0;
}
