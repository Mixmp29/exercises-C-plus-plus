#include <iostream>
#include <vector>

// Упражнение 5.5. Напишите собественную версию программы перебора значения
// числовой оценки в символ с использованием оператора if else.

int main() {
  std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
  int grade;
  std::string lettergrade;

  std::cin >> grade;

  if (grade < 60) {
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
  }

  std::cout << "Grade is " << lettergrade << std::endl;
}