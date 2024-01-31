// Упражнение 15.22. Укажите имена некоторых из наиболее вероятных виртуальных
// функций, а также открытых и защищенных членов для класса, выбранного в
// предыдущем упражнении.

// В моем случае предполагается, что функции звонков, записи видео и фотографий
// является базовой вещью, которая выполняется одинаково. Следовательно они
// могут просто наследоваться через открытый доступ. Система телефонов же может
// отличаться в зависимости от марки, следовательно стоит сделать эту функцию
// виртуальной для того, чтобы каждая марка описала свой скрипт. Описание
// системы является реализацией смартфона, следовательно она должна быть
// закрыта.

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

int main() {}