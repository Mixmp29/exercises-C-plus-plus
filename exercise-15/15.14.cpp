// Упражнение 15.14. С учетом классов из предыдущего упражнения и следующих
// объектов укажите, какие из версий функций будут применены во время
// выполнения:

#include <iostream>
#include <string>

class base {
 public:
  std::string name() {
    std::cout << "name()";
    return basename;
  }
  virtual void print(std::ostream &os) { os << basename; }

 private:
  std::string basename = "somename";
};

class derived : public base {
 public:
  void print(std::ostream &os) override {
    base::print(os);
    os << " " << i;
  }

 private:
  int i = 1;
};

int main() {
  base bobj;
  derived dobj;
  base *bp1 = &bobj;
  base *bp2 = &dobj;
  base &br1 = bobj;
  base &br2 = dobj;

  std::cout << "(a)" << std::endl;
  bobj.print(std::cout);  // base.
  std::cout << std::endl;

  std::cout << "(b)" << std::endl;
  dobj.print(std::cout);  // derived.
  std::cout << std::endl;

  std::cout << "(c)" << std::endl;
  bp1->name();  // base.
  std::cout << std::endl;

  std::cout << "(d)" << std::endl;
  bp2->name();  // derived.
  std::cout << std::endl;

  std::cout << "(e)" << std::endl;
  br1.print(std::cout);  // base.
  std::cout << std::endl;

  std::cout << "(f)" << std::endl;
  br2.print(std::cout);  // derived.
  std::cout << std::endl;
}