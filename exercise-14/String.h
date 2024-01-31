#pragma once

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class String {
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const String &);
  // 14.18.
  friend bool operator<(const String &, const String &);
  friend bool operator>(const String &, const String &);
  friend bool operator<=(const String &, const String &);
  friend bool operator>=(const String &, const String &);

 public:
  String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const char *);
  String(std::initializer_list<char> il);
  String(const String &);
  String(String &&) noexcept;
  String &operator=(const String &);
  String &operator=(String &&) noexcept;
  // 14.26
  char &operator[](size_t);
  const char &operator[](size_t) const;
  ~String();

  void push_back(const char &);
  void reserve(size_t);
  void resize(size_t);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  char *begin() const { return elements; }
  char *end() const { return first_free; }

 private:
  std::allocator<char> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) reallocate();
  }

  std::pair<char *, char *> alloc_n_copy(const char *, const char *);
  void free();
  void reallocate();

  char *elements;
  char *first_free;

  char *cap;
};

void String::reserve(size_t n) {
  if (capacity() < n) {
    auto newcapacity = n;
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;

    for (size_t i = 0; i < size(); ++i)
      alloc.construct(dest++, std::move(*elem++));
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
  }
}

void String::resize(size_t n) {
  if (size() < n) {
    auto p = first_free;
    while (p != elements + n) alloc.destroy(--p);
    first_free = p;
  } else {
    for (auto p = size(); p < size() + n; ++p) push_back(char());
  }
}

void String::push_back(const char &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void String::free() {
  if (elements) {
    for (auto p = first_free; p != elements;) alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

String::String(const char *ch) {
  auto b = ch;
  auto e = ch;
  while (*e != '\0') e++;
  auto newdata = alloc_n_copy(b, e);
  elements = newdata.first;
  first_free = cap = newdata.second;
}

String::String(std::initializer_list<char> il)
    : elements(nullptr), first_free(nullptr), cap(nullptr) {
  for (auto s : il) push_back(s);
}

String::String(const String &s) {
  std::cout << "String(const String &)" << std::endl;
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

String::String(String &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
  std::cout << "String(String &&)" << std::endl;
  s.elements = s.first_free = s.cap = nullptr;
}

String::~String() { free(); }

String &String::operator=(const String &rhs) {
  std::cout << "operator=(const String &)" << std::endl;
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

String &String::operator=(String &&rhs) noexcept {
  std::cout << "operator=(const String &&)" << std::endl;
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;

    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }

  return *this;
}

// 14.26
char &String::operator[](size_t n) { return elements[n]; }
const char &String::operator[](size_t n) const { return elements[n]; }

void String::reallocate() {
  auto newcapacity = size() ? size() * 2 : 1;
  auto newdata = alloc.allocate(newcapacity);

  auto dest = newdata;
  auto elem = elements;

  for (size_t i = 0; i < size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();

  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

// 14.18
bool operator==(const String &lhs, const String &rhs) {
  if (lhs.size() == rhs.size()) {
    auto bl = lhs.begin();
    auto br = rhs.begin();
    auto e = lhs.end();
    while (bl != e)
      if (*bl++ != *br++) return false;
  }

  return true;
}

bool operator!=(const String &lhs, const String &rhs) { return !(lhs == rhs); }

// 14.18.

// Элементы векторов сначала сравниваются по знаку оператора сравнения слева
// направо до первого несоответствия, а только потом смотрят на размер.
bool operator<(const String &lhs, const String &rhs) {
  // Найти минимльный вектор, чтобы не выйти за рамки.
  size_t min;
  if (lhs.size() < rhs.size())
    min = lhs.size();
  else
    min = rhs.size();

  // Если хотя бы один элемент не равен второму и он меньше
  for (size_t i = 0; i < min; ++i)
    if (*(lhs.begin() + i) != *(rhs.begin() + i) &&
        *(lhs.begin() + i) < *(rhs.begin() + i))
      return true;
    else
      return false;

  if (lhs != rhs && lhs.size() < rhs.size())
    return true;
  else
    return false;

  // Наверное можно было сделать лучше, придумал все из головы.
}
bool operator>(const String &lhs, const String &rhs) { return rhs < lhs; }
bool operator<=(const String &lhs, const String &rhs) { return !(lhs > rhs); }
bool operator>=(const String &lhs, const String &rhs) { return !(lhs < rhs); }