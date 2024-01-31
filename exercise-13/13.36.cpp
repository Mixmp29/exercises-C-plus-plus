// Упражнение 13.36. Разработайте и реализуйте соответствующий класс Folder.
// Этот класс должен содержать набор указателей на сообщения в этой папке.

#include <set>
#include <string>

class Message;

// Папка (folder) - каталог, содержащий сообщения (или же указатели на них).
// Описание класса Folder не сделно полноценно, но из реализации Message можно
// заметить, что набор указателей позволяет содержать указатели на разные
// объекты типа Folder. Из этого следует, что может быть несколько объектов типа
// Folder на один Message. В книге также написано, что нужно сделать
// соответствующие операции копирования. Следовательно нужно учесть, что если
// был копирован объект Folder, то это скажется на наборе в Message, который
// хранит указатели на папки, содержащие эти сообщения.

// В целом функций addMsg и remMsg более чем достаточно, для работы с Message.
// Однако нужно учитывать, что у классов синтезируются функции управления
// копированием: конструктор обычный, конструктор копией, присвоение копией и
// деструктор. Если сделать класс только с функциями addMsg и remMsg, то при
// копировании объекта типа Folder копируются указатели, но это никак не
// скажется на самих Message в наборе. Из этого следует, что нужно либо удалить
// эти функции через delete, запретив таким образом какие-либо действия с
// Folder, либо прописать им соответствующее поведение в разных случаях.

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

 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
};

void Folder::add_to_Messages() {
  // Для каждого сообщения (указателя на сообщение) вызвать функцию-член save,
  // которая добавит указатель на папку в наборе folders объекта Message и
  // добавит указатель на сообщение в messages объекта Folder.
  for (auto msg : messages) msg->save(*this);
}

void Folder::remove_from_Messages() {
  // Для каждого сообщения (указателя на сообщение) вызвать функцию-член remove,
  // которая удалит указатель на папку в наборе folders объекта Message и удалит
  // указатель на сообщение из messages объекта Folder.
  for (auto msg : messages) msg->remove(*this);
}

// Копировать набор из копирумого объекта типа Folder.
Folder::Folder(const Folder& m) : messages(m.messages) { add_to_Messages(); };
Folder::~Folder() { remove_from_Messages(); };

Folder& Folder::operator=(const Folder& rhs) {
  // Удалить элементы из левого операнда.
  remove_from_Messages();
  // Скопировать правый операнд.
  messages = rhs.messages;
  // Обработать объекты Message по указателям.
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

Message& Message::operator=(const Message& rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

int main() {}