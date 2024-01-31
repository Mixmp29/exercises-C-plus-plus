// Упражнение 13.40. Добавьте в класс StrVec конструктор, получающий аргумент
// типа initializer_list<string>.

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec {
 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string> il);
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
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

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

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