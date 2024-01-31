// Упражнение 13.31. Снабдите свой класс оператором < и определите вектор
// объектов класса HasPtr. Вставьте в вектор несколько элементов, а затем
// отсортируйте его (sort()). Обратите внимание на то, когда вызывает функция
// swap().

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
  ~HasPtr() { delete ps; }

  HasPtr &operator=(HasPtr rhs) {
    swap(*this, rhs);  // Удобно.
    return *this;
  }

  bool operator<(HasPtr rhs) { return (*this->ps < *rhs.ps); }

 private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  std::cout << "swap(" << *lhs.ps << ", " << *rhs.ps << ")" << std::endl;
}

int main() {
  std::vector<HasPtr> vec;
  vec.push_back(HasPtr("Some"));
  vec.push_back(HasPtr("string"));
  vec.push_back(HasPtr("here"));
  vec.push_back(HasPtr("hello"));
  vec.push_back(HasPtr("by"));
  vec.push_back(HasPtr("the"));
  vec.push_back(HasPtr("way"));

  std::sort(vec.begin(), vec.end());
}