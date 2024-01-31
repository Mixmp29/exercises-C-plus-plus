// Упражнение 7.4. Напишите класс по имени Person, представляющий имя и адрес
// человека. Используйте для содержания каждого из этих членов тип string. В
// последующих упражениях в этот класс будут добавлены новые стредства.

#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
  std::string Name = "";
  std::string Address = "";
};

#endif