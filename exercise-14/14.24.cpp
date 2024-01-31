// Упражнение 14.24. Примите решение, нуждается ли класс из упражнения 7.40
// раздела 7.5.1 (стр. 377) в операторах копирования и присвоения при
// перемещении. Если да, то определите эти операторы.

// Да, надо бы. У меня TransferEntries() по сути конструктор присвоения
// копированием. Но без присвоения даты.

#include "Diary2.h"

int main() {
  Diary plan(12, 12, 2023, "Sit home and do homework.");
  plan.addEntry("Cook the fish.");
  std::cout << plan;

  std::cin >> plan;
  std::cout << plan;

  Diary plan2;
  std::cout << plan2;

  plan2.changeDate(14, 12, 2023).TransferEntries(plan).addEntry("Play in COD.");
  std::cout << plan2;

  Diary plan3(15, 12, 2023);
  plan3.addEntries(std::cin);
  std::cout << plan3;

  Diary plan4 = (plan2 += plan3).changeDate(17, 12, 2023);
  std::cout << plan4;

  Diary plan5 = plan4;

  plan4 = plan2;

  Diary planass = std::move(plan5);
  plan2 = std::move(planass);
}