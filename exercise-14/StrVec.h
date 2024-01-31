#pragma once

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec {
  // 14.18
  friend bool operator==(const StrVec &, const StrVec &);
  friend bool operator!=(const StrVec &, const StrVec &);
  friend bool operator<(const StrVec &, const StrVec &);
  friend bool operator>(const StrVec &, const StrVec &);
  friend bool operator<=(const StrVec &, const StrVec &);
  friend bool operator>=(const StrVec &, const StrVec &);

 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string>);
  StrVec(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(const StrVec &);
  StrVec &operator=(StrVec &&) noexcept;
  StrVec &operator=(std::initializer_list<std::string>);
  // 14.26
  std::string &operator[](size_t);
  const std::string &operator[](size_t) const;
  ~StrVec();

  void push_back(const std::string &);
  void reserve(size_t);
  void resize(size_t);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

 private:
  std::allocator<std::string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) reallocate();
  }

  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();

  std::string *elements;
  std::string *first_free;

  std::string *cap;
};

void StrVec::reserve(size_t n) {
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

void StrVec::resize(size_t n) {
  if (size() < n) {
    auto p = first_free;
    while (p != elements + n) alloc.destroy(--p);
    first_free = p;
  } else {
    for (auto p = size(); p < size() + n; ++p) push_back("");
  }
}

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(
    const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  if (elements) {
    for (auto p = first_free; p != elements;) alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

StrVec::StrVec(std::initializer_list<std::string> il)
    : elements(nullptr), first_free(nullptr), cap(nullptr) {
  for (auto s : il) push_back(s);
}

StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
  s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;

    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }

  return *this;
}

// 14.23.
StrVec &StrVec::operator=(std::initializer_list<std::string> il) {
  auto data = alloc_n_copy(il.begin(), il.end());
  free();
  elements = data.first;
  first_free = cap = data.second;

  return *this;
}

// 14.26
std::string &StrVec::operator[](size_t n) { return elements[n]; }
const std::string &StrVec::operator[](size_t n) const { return elements[n]; }

void StrVec::reallocate() {
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
bool operator==(const StrVec &lhs, const StrVec &rhs) {
  if (lhs.size() == rhs.size()) {
    auto bl = lhs.begin();
    auto br = rhs.begin();
    auto e = lhs.end();
    while (bl != e)
      if (*bl++ != *br++) return false;
  }

  return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) { return !(lhs == rhs); }

// Элементы векторов сначала сравниваются по знаку оператора сравнения слева
// направо до первого несоответствия, а только потом смотрят на размер.
bool operator<(const StrVec &lhs, const StrVec &rhs) {
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
bool operator>(const StrVec &lhs, const StrVec &rhs) { return rhs < lhs; }
bool operator<=(const StrVec &lhs, const StrVec &rhs) { return !(lhs > rhs); }
bool operator>=(const StrVec &lhs, const StrVec &rhs) { return !(lhs < rhs); }