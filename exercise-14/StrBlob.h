#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend StrBlobPtr;
  friend ConstStrBlobPtr;

  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  // 14.18.
  friend bool operator<(const StrBlob &, const StrBlob &);
  friend bool operator>(const StrBlob &, const StrBlob &);
  friend bool operator<=(const StrBlob &, const StrBlob &);
  friend bool operator>=(const StrBlob &, const StrBlob &);

 public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  // 14.26
  std::string &operator[](size_t);
  const std::string &operator[](size_t) const;

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
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  // 14.18
  friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
  friend StrBlobPtr operator+(const StrBlobPtr &, size_t);
  friend StrBlobPtr operator-(const StrBlobPtr &, size_t);

 public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  // 14.26
  std::string &operator[](size_t n) {
    auto p = check(curr + n, "out of range in operator []");
    return (*p)[curr + n];
  }
  const std::string &operator[](size_t n) const {
    auto p = check(curr + n, "out of range in operator []");
    return (*p)[curr + n];
  }

  // 14.27
  StrBlobPtr &operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }
  StrBlobPtr &operator--() {
    --curr;
    check(curr, "decrement past being of StrBlobPtr");
    return *this;
  }

  StrBlobPtr operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
  }
  StrBlobPtr operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
  }

  // 14.30
  std::string &operator*() const;
  std::string *operator->() const;
  StrBlobPtr &incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

class ConstStrBlobPtr {
  friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  // 14.18
  friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, size_t);
  friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, size_t);

 public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  // 14.26
  std::string &operator[](size_t n) {
    auto p = check(curr + n, "out of range in operator []");
    return (*p)[curr + n];
  }
  const std::string &operator[](size_t n) const {
    auto p = check(curr + n, "out of range in operator []");
    return (*p)[curr + n];
  }

  // 14.27
  ConstStrBlobPtr &operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }
  ConstStrBlobPtr &operator--() {
    --curr;
    check(curr, "decrement past being of StrBlobPtr");
    return *this;
  }

  ConstStrBlobPtr operator++(int) {
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
  }
  ConstStrBlobPtr operator--(int) {
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
  }

  // 14.30
  const std::string &operator*() const;
  const std::string *operator->() const;
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

// 14.26.
std::string &StrBlob::operator[](size_t n) { return (*data)[n]; }
const std::string &StrBlob::operator[](size_t n) const { return (*data)[n]; }

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

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() {
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const {
  auto ret = ConstStrBlobPtr(*this, data->size());
  return ret;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
    std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret) throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size()) throw std::out_of_range(msg);
  return ret;
}

std::string &StrBlobPtr::operator*() const {
  auto p = check(curr, "dereference past and");
  return (*p)[curr];
}

std::string *StrBlobPtr::operator->() const { return &this->operator*(); }

StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(
    std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret) throw std::runtime_error("unbound ConstStrBlobPtr");
  if (i >= ret->size()) throw std::out_of_range(msg);
  return ret;
}

const std::string &ConstStrBlobPtr::operator*() const {
  auto p = check(curr, "dereference past and");
  return (*p)[curr];
}

const std::string *ConstStrBlobPtr::operator->() const {
  return &this->operator*();
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

// 14.18.
bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
  return lhs.data < rhs.data;
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
  return lhs.data > rhs.data;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
  return lhs.data <= rhs.data;
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
  return lhs.data >= rhs.data;
}

// 14.28.
StrBlobPtr operator+(const StrBlobPtr &lhs, size_t rhs) {
  StrBlobPtr ret = lhs;
  ret.check(ret.curr + rhs, "out of range in operator []");
  ret.curr += rhs;
  return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, size_t rhs) {
  StrBlobPtr ret = lhs;
  ret.check(ret.curr - rhs, "out of range in operator []");
  ret.curr -= rhs;
  return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs == rhs);
}

// 14.18.
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return rhs.curr - lhs.curr > 0;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(rhs < lhs);
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs < rhs);
}

// 14.28.
ConstStrBlobPtr operator+(const ConstStrBlobPtr &lhs, size_t rhs) {
  ConstStrBlobPtr ret = lhs;
  ret.check(ret.curr + rhs, "out of range in operator []");
  ret.curr += rhs;
  return ret;
}

ConstStrBlobPtr operator-(const ConstStrBlobPtr &lhs, size_t rhs) {
  ConstStrBlobPtr ret = lhs;
  ret.check(ret.curr - rhs, "out of range in operator []");
  ret.curr -= rhs;
  return ret;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return !(lhs == rhs);
}

// 14.18.
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return rhs.curr - lhs.curr > 0;
}
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return rhs < lhs;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return !(rhs < lhs);
}
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return !(lhs < rhs);
}