#include <iostream>
#include <vector>

// Упражнение 5.6. Перепишите программу оценки так, чтобы использовать условный
// оператор (см. раздел 4.7, стр. 208) вместо оператора if else.

int main() {
  std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
  int grade;
  std::string lettergrade;

  std::cin >> grade;

  /* if (grade < 60) {
    lettergrade = scores[0];
  } else {
    lettergrade = scores[(grade - 50) / 10];

    if (grade != 100) {
      if (grade % 10 < 3) {
        lettergrade += '-';
      } else if (grade % 10 > 7) {
        lettergrade += '+';
      }
    }
  } */

  lettergrade = (grade < 60)
                    ? scores[0]
                    : scores[(grade - 50) / 10] + ((grade == 100)     ? ""
                                                   : (grade % 10 < 3) ? "-"
                                                   : (grade % 10 > 7) ? "+"
                                                                      : "");
  // Вариант с условным оператором. Получилось компактно и даже вполне понятно.

  std::cout << "Grade is " << lettergrade << std::endl;
}