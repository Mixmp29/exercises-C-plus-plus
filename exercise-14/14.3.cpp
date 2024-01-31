// Упражнение 14.3. Классы string и vector определяют перегруженный оператор ==,
// применимый для сравнения объектов этим типов. Если векторы svec1 и svec2
// содержат строк, объясните, какая из версий оператора == применяется в каждом
// из следющих выражений:

#include <string>
#include <vector>

int main() {
  std::vector<std::string> svec1;
  std::vector<std::string> svec2;

  // Встроенный операторо стравнения.
  if ("cobble" == "stoen")
    ;

  // Перегруженный оператор '==' типа string.
  if (svec1[0] == svec2[0])
    ;

  // Перегруженный оператор '==' типа vector.
  if (svec1 == svec2)
    ;

  // Тут опечатка наверное (в книге), но даладно.
  // Перегруженный оператор '==' типа sting.
  if (svec1[0] == "stone")
    ;
}