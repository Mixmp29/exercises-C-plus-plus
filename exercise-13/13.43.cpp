// Упражнение 13.43. Перепишите функцию-член free() так, чтобы для удаления
// элементов вместо цикла for использовалась функция for_each() и
// лямбда-выражение (см. раздел 10.3.2, стр. 497). Какую реализацию вы
// предпочитаете и почему?

// В данном случае реализация и использование лямбда-выражения является
// неудобной, так как нужно работать с указателем, который нужно передавать при
// вызове destroy(), а for_each() же работает со значениями последовательности.
// То есть нужно передать через список захвата заранее созданный указатель,
// через который будет происходить удаление. Более того, для того, чтобы
// двигаться по последовательности указателем нужно испольовать инкремент, а
// переданное значение по списку захвата нельзя просто так изменить, так как все
// переданные значения являются const. Для изменения нужно использовать mutable,
// что может негативно сказаться на коде в зависимости от реализации, либо
// использовать ссылку или указатель на объект, который можно спокойно изменить.

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
  void chk_n_alloc() {
    if (size() == capacity()) reallocate();
  }

  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();

  using alloc_type = std::allocator<std::string>;
  alloc_type alloc;

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
    // С помощью своих реализаций begin() и end() теперь возможно использовать
    // библиотечные алгоритмы.
    // В списке захвата лямбда-выражения следует поставить this, так как объект
    // является локальной для нее (this неявно передается как параметр фунцкии:
    // StrVec* this).
    auto p = elements;
    std::for_each(this->begin(), this->end(),
                  [this, &p](std::string s) { alloc.destroy(p++); });
    // Эквивалентно
    //                [this, p]() { (*this).alloc.destroy(p); });
    //                [this, p]() { this->alloc.destroy(p); });

    // for (auto p = first_free; p != elements;) alloc.destroy(--p);
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

int main() {}