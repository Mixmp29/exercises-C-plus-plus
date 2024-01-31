// Упражнение 13.55. Добавьте в класс StrBlob функцию push_back() в версии
// ссылки на r-значение.

#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class ConstStrBlobPtr;

class StrBlob {
  friend ConstStrBlobPtr;

 public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  size_type size() const { return data->size(); }
  void push_back(const std::string& t) { data->push_back(t); }
  void push_back(const std::string& t) const { data->push_back(t); }
  // Конструктор вектора должен понять кого нужно push_ba'чить.
  void push_back(std::string&& t) { data->push_back(t); }
  void push_back(std::string&& t) const { data->push_back(t); }
  void pop_back();
  void pop_back() const;
  std::string& front();
  std::string& front() const;
  std::string& back();
  std::string& back() const;
  std::string& curr(size_type);
  std::string& curr(size_type) const;
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string& msg) const;
};

class ConstStrBlobPtr {
  friend bool compare(ConstStrBlobPtr&, ConstStrBlobPtr&);

 public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  std::string& deref() const;
  ConstStrBlobPtr& incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string&) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string& msg) const {
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

std::string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return this->data->front();
}

std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

std::string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

std::string& StrBlob::curr(size_type index) {
  check(index, "index out of range");
  return *(data->begin() + index);
}
std::string& StrBlob::curr(size_type index) const {
  check(index, "index out of range");
  return *(data->begin() + index);
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const {
  auto ret = ConstStrBlobPtr(*this, data->size());
  return ret;
}

bool compare(ConstStrBlobPtr& a, ConstStrBlobPtr& b) {
  return a.curr != b.curr;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(
    std::size_t i, const std::string& msg) const {
  auto ret = wptr.lock();
  if (!ret) throw std::runtime_error("unbound ConstStrBlobPtr");
  if (i >= ret->size()) throw std::out_of_range(msg);
  return ret;
}

std::string& ConstStrBlobPtr::deref() const {
  auto p = check(curr, "dereference past and");
  return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
  check(curr, "increment past end of ConstStrBlobPtr");
  ++curr;
  return *this;
}