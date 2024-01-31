// Упражнение 13.47. Снабдите конструктором копий и оператором присвоения копии
// String из упражнения 13.44. раздела 13.5 (стр. 672), функции которого выводят
// сообщения при каждом вызове.

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class String {
 public:
  String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  String(char *);
  String(std::initializer_list<char> il);
  String(const String &);
  String &operator=(const String &);
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

String::String(char *ch) {
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

String::~String() { free(); }

String &String::operator=(const String &rhs) {
  std::cout << "operator=(const String &)" << std::endl;
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

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