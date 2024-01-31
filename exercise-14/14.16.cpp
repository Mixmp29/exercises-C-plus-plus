// Упражнение 14.16. Определите операторы равенства и неравенства для классов
// StrBlob (см. раздел 12.1.1, стр. 582), StrBlobPtr (см. раздел 12.1.6, стр.
// 604), StrVec (см. раздел 13.5, стр. 666) и String (см. раздел 13.5, стр.
// 671).

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class ConstStrBlobPtr;

class StrBlob {
  friend ConstStrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  //              ^
  //              |
  //  Необязательно. Тело использует перегруежнный оператор '=='.

 public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  size_type size() const { return data->size(); }
  void push_back(const std::string &t) { data->push_back(t); }
  void push_back(const std::string &t) const { data->push_back(t); }
  void push_back(std::string &&t) { data->push_back(t); }
  void push_back(std::string &&t) const { data->push_back(t); }
  void pop_back();
  void pop_back() const;
  std::string &front();
  std::string &front() const;
  std::string &back();
  std::string &back() const;
  std::string &curr(size_type);
  std::string &curr(size_type) const;
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};

class ConstStrBlobPtr {
  friend bool operator==(ConstStrBlobPtr &, ConstStrBlobPtr &);
  friend bool operator!=(ConstStrBlobPtr &, ConstStrBlobPtr &);

 public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  std::string &deref() const;
  ConstStrBlobPtr &incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

void StrBlob::pop_back() const {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return this->data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

std::string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

std::string &StrBlob::curr(size_type index) {
  check(index, "index out of range");
  return *(data->begin() + index);
}
std::string &StrBlob::curr(size_type index) const {
  check(index, "index out of range");
  return *(data->begin() + index);
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const {
  auto ret = ConstStrBlobPtr(*this, data->size());
  return ret;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(
    std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret) throw std::runtime_error("unbound ConstStrBlobPtr");
  if (i >= ret->size()) throw std::out_of_range(msg);
  return ret;
}

std::string &ConstStrBlobPtr::deref() const {
  auto p = check(curr, "dereference past and");
  return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr() {
  check(curr, "increment past end of ConstStrBlobPtr");
  ++curr;
  return *this;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
  return lhs.data == rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs == rhs);
}

bool operator==(ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs) {
  return lhs.curr == rhs.curr;
}

bool operator!=(ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs) {
  return !(lhs == rhs);
}

/////////////////////////////////////////////////////////////////

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class String {
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const String &);

 public:
  String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const char *);
  String(std::initializer_list<char> il);
  String(const String &);
  String(String &&) noexcept;
  String &operator=(const String &);
  String &operator=(String &&) noexcept;
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

bool operator==(const String &lhs, const String &rhs) {
  // Если размеры равны
  if (lhs.size() == rhs.size()) {
    // Сравнить каждый элемент
    for (size_t i = 0; i < lhs.size(); ++i)
      if (*(lhs.begin() + i) != *(rhs.begin() + i)) return false;
  }

  return true;
}
bool operator!=(const String &lhs, const String &rhs) { return !(lhs == rhs); }