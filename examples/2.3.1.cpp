#include <iostream>

void func2(int &refVal3) { refVal3 += 100; }

void func1(int &refVal2) { refVal2 += 100; }

int main() {
  int ival = 1024;
  int &refVal = ival;

  func1(ival);
  func2(ival);

  std::cout << ival << std::endl;
  std::cout << refVal << std::endl;
}