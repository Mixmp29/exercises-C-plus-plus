// Упражнение 7.57. Определите собственную версию Account.

#include <string>

class Account {
 public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);

 private:
  std::string owner;
  double amount;
  static double interestRate;
  static double initRate();
};

void Account::rate(double newRate) { interestRate = newRate; }

double Account::initRate() { return 5; }

double Account::interestRate = initRate();
//                                ^
//                                |
// Не сразу долшло как это получается без Account::. Это как определение
// фукнции-члена, там тоже доступны закрытые члены класса.
// Ключевое слово тут ОПРЕДЕЛЕНИЕ. То есть, когда член
// определяется здесь, он как бы это делает внутри класса (в его области
// видимости).

int main() {}