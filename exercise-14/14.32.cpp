// Упражнение 14.32. Определите класс, содержащий указатель на класс StrBlobPtr.
// Определите перегруженный оператор стрелки для этого класса.

#include <string>

#include "StrBlob.h"

class Ptr {
 public:
  Ptr(StrBlobPtr& sb) : obj(&sb) {}

  std::string* operator->() { return obj->operator->(); }

 private:
  StrBlobPtr* obj;
};

int main() {
  StrBlob a1 = {"hi", "bye", "now"};
  StrBlobPtr p(a1);
  Ptr ptr(p);
  *p = "okey";
  std::cout << ptr->size() << std::endl;
  std::cout << (*p).size() << std::endl;
}