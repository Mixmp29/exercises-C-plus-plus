#include <iostream>
// Упражнение 2.40. Напишите собственную версию класса Sales_data.

struct Sales_data {
  std::string bookNo;  // std из iostream, соответственно string оттуда же
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() { return 0; }