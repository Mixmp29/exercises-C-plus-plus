// Упражнение 13.49. Добавьте конструктор перемещения и оператор присваивания
// при перемещении в классы StrVec, String и Message.

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec {
 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string> il);
  StrVec(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(const StrVec &);
  StrVec &operator=(StrVec &&) noexcept;
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

//////////////////////////////////////////////////////////////

class String {
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
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;

    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
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

//////////////////////////////////////////////////////////////

#include <set>
#include <string>

class Message;

class Folder {
 public:
  Folder() = default;
  Folder(const Folder &);
  Folder(Folder &&);
  ~Folder();

  Folder &operator=(const Folder &);
  Folder &operator=(Folder &&);

  void addMsg(Message *);
  void remMsg(Message *);

 private:
  std::set<Message *> messages;
  void add_to_Messages();
  void remove_from_Messages();
  void move_Messages(Folder *);
};

class Message {
 public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  Message(Message &&);
  ~Message();

  Message &operator=(const Message &);
  Message &operator=(Message &&);

  void save(Folder &);
  void remove(Folder &);
  void addFlr(Folder *);
  void remFlr(Folder *);

 private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
  void move_Folders(Message *m);
};

void Folder::add_to_Messages() {
  for (auto msg : messages) msg->save(*this);
}

void Folder::remove_from_Messages() {
  for (auto msg : messages) msg->remove(*this);
}

void Folder::move_Messages(Folder *f) {
  messages = std::move(f->messages);
  for (auto m : messages) {
    m->remove(*f);
    m->save(*this);
  }

  f->messages.clear();
}

Folder::Folder(const Folder &m) : messages(m.messages) { add_to_Messages(); };
Folder::Folder(Folder &&f) { move_Messages(&f); };
Folder::~Folder() { remove_from_Messages(); };

Folder &Folder::operator=(const Folder &rhs) {
  remove_from_Messages();
  messages = rhs.messages;
  add_to_Messages();
  return *this;
}

Folder &Folder::operator=(Folder &&rhs) {
  if (this != &rhs) {
    remove_from_Messages();
    move_Messages(&rhs);
  }

  return *this;
}

void Folder::addMsg(Message *m) { messages.insert(m); }
void Folder::remMsg(Message *m) { messages.erase(m); }

void Message::add_to_Folders(const Message &m) {
  for (auto f : m.folders) f->addMsg(this);
}

void Message::remove_from_Folders() {
  for (auto f : folders) f->remMsg(this);
}

void Message::move_Folders(Message *m) {
  folders = std::move(m->folders);

  for (auto f : folders) {
    f->remMsg(m);
    f->addMsg(this);
  }

  m->folders.clear();
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m);
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
  move_Folders(&m);
}

Message::~Message() { remove_from_Folders(); }

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::addFlr(Folder *f) { folders.erase(f); }

void Message::remFlr(Folder *f) { folders.erase(f); }

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

Message &Message::operator=(Message &&rhs) {
  if (this != &rhs) {
    remove_from_Folders();
    contents = std::move(rhs.contents);
    move_Folders(&rhs);
  }
  return *this;
}