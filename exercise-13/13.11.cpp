// Упражнение 13.11. Добавьте деструктор в класс HasPtr из предыдущих
// упражнений.

#include <string>

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
  ~HasPtr() {
    delete ps;
  }  // Насколько я понял нужно сделать освобождение string явно, иначе будет
     // просто удален указатель, а не объект.

  HasPtr &operator=(const HasPtr &rhs) {
    // Провтыкал тут ещё одну важную вещь. Надо освободить область памяти, на
    // которую указывает ps, а только потом присваивать ему новую строку. Иначе
    // указатель поменяет свой объект, а старое значение так и не удалится.
    // ps = new std::string(*rhs.ps);
    std::string *newp = new std::string(*rhs.ps);
    delete ps;  // <- Не забыть освободить старый объект. ps теперь пустой
                // (потерянный).
    ps = newp;
    i = rhs.i;
    return *this;  // <- Про это забывать не нужно.
  }

 private:
  std::string *ps;
  int i;
};