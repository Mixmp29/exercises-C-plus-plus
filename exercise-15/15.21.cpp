// Упражнение 15.21. Выберите одну из следующих общих абстракций, содержащих
// семейство типов (или любую собственную). Организуйте типы в иерархию
// наслдедования.

// Попробую организовать свою с иерархией "Телефон".

#include <iostream>
#include <string>

class Phone {
 public:
  void ring();

 protected:
  std::string number;
};

class SmartPhone : public Phone {
 public:
  void video();
  void photo();

 private:
  virtual void system() = 0;
};

class Apple : public SmartPhone {
 public:
  void Apple_functions();

 private:
  void system() override{};
};

class Samsung : public SmartPhone {
 public:
  void Samsung_functions();

 private:
  void system() override{};
};
class Xiaomi : public SmartPhone {
 public:
  void Xiaomi_functions();

 private:
  void system() override{};
};