// Упражнение 13.37. Добавьте в класс Message функции-члены удаления и вставки
// заданного Folder* в folders. Эти члены аналогичны функциям-членам addMsg() и
// remMsg() класса Folder.

#include <set>
#include <string>

class Message;

class Folder {
 public:
  Folder() = default;
  Folder(const Folder&);
  ~Folder();

  Folder& operator=(const Folder&);

  void addMsg(Message*);
  void remMsg(Message*);

 private:
  std::set<Message*> messages;
  void add_to_Messages();
  void remove_from_Messages();
};

class Message {
 public:
  explicit Message(const std::string& str = "") : contents(str) {}
  Message(const Message&);
  ~Message();

  Message& operator=(const Message&);

  void save(Folder&);
  void remove(Folder&);
  void addFlr(Folder*);
  void remFlr(Folder*);

 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
};

void Folder::add_to_Messages() {
  for (auto msg : messages) msg->save(*this);
}

void Folder::remove_from_Messages() {
  for (auto msg : messages) msg->remove(*this);
}

Folder::Folder(const Folder& m) : messages(m.messages) { add_to_Messages(); };
Folder::~Folder() { remove_from_Messages(); };

Folder& Folder::operator=(const Folder& rhs) {
  remove_from_Messages();
  messages = rhs.messages;
  add_to_Messages();
  return *this;
}

void Folder::addMsg(Message* m) { messages.insert(m); }
void Folder::remMsg(Message* m) { messages.erase(m); }

void Message::add_to_Folders(const Message& m) {
  for (auto f : m.folders) f->addMsg(this);
}

void Message::remove_from_Folders() {
  for (auto f : folders) f->remMsg(this);
}

Message::Message(const Message& m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m);
}

Message::~Message() { remove_from_Folders(); }

void Message::save(Folder& f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder& f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::addFlr(Folder* f) { folders.erase(f); }

void Message::remFlr(Folder* f) { folders.erase(f); }

Message& Message::operator=(const Message& rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

int main() {}