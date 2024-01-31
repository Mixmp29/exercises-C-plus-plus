// Упражнение 13.34. Напишите класс Message, как описано в этом разделе.

#include <set>
#include <string>

class Message;

class Folder {
 public:
  Folder(Message* p = nullptr) : ptr(p) {}
  // Синтезируемых функций пока будет достаточно.
  Folder& addMsg(Message*);
  Folder& remMsg(Message*);

 private:
  Message* ptr;
};

class Message {
 public:
  explicit Message(const std::string& str = "") : contents(str) {}
  Message(const Message&);
  ~Message();

  void save(Folder&);
  void remove(Folder&);

 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
};

Folder& Folder::addMsg(Message* m) { ptr = m; }
Folder& Folder::remMsg(Message* m) { ptr = nullptr; }

void Message::save(Folder& f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder& f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message& m) {
  for (auto f : m.folders) f->addMsg(this);
}

Message::Message(const Message& m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m);
}

void Message::remove_from_Folders() {
  for (auto f : folders) f->remMsg(this);
}

Message::~Message() { remove_from_Folders(); }

Message& Message::operator=(const Message& rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}