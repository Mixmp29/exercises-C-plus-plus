// Упражнение 12.7. Переделайте предыдущее упражненеие, используя на сей раз
// указатель shared_ptr.

#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> factory() {
  std::shared_ptr<std::vector<int>> pv = std::make_shared<std::vector<int>>();
  return pv;
}

std::shared_ptr<std::vector<int>> read_factory() {
  std::shared_ptr<std::vector<int>> pv = factory();
  int val;
  while (std::cin >> val) pv->push_back(val);
  return pv;
}

void print_factory() {
  auto pv = read_factory();
  for (auto elem : *pv) std::cout << elem << " ";
  std::cout << std::endl;

  // Можно забить на удаление, share_ptr с этим справится.
}

int main() { print_factory(); }