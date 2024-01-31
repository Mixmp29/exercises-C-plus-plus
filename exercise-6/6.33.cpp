#include <iostream>
#include <vector>

std::vector<int>::iterator print(std::vector<int>::iterator begin,
                                 std::vector<int>::iterator end) {
  if (begin != end) std::cout << *print(begin, end - 1) << std::endl;
  return end;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  print(v.begin(), v.end());
}