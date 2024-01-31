// Упражнение 14.44. Напишите собственную версию простого калькулятора
// способного выполнять бинарные операции.

#include <functional>
#include <iostream>
#include <map>
#include <string>

int add(int a, int b) { return a + b; }

struct mydiv {
  int operator()(int a, int b) { return a / b; }
};

auto mod = [](int a, int b) { return a % b; };

int main() {
  std::map<std::string, std::function<int(int, int)>> binops = {
      {"+", add},     {"-", std::minus<int>()},
      {"/", mydiv()}, {"*", [](int a, int b) { return a * b; }},
      {"%", mod},
  };

  while (1) {
    std::string slhs, op, srhs;
    int lhs, rhs;

    std::cin >> slhs >> op >> srhs;

    if (!std::cin) break;

    lhs = atoi(slhs.c_str());
    rhs = atoi(srhs.c_str());

    std::cout << binops[op](lhs, rhs) << std::endl;
  }
}