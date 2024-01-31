#pragma once

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