#pragma once

#include <string>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
  ~HasPtr() { delete ps; }

  HasPtr &operator=(HasPtr rhs) {
    /* std::string *newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i; */

    swap(*this, rhs);  // Удобно.

    return *this;
  }

 private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}