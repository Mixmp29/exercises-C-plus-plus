// Упражнние 2.5. Определите тип каждого из следующих литералов. Объясните
// различия между ними
int main() {
  'a';   // char
  L'a';  // wchar_t
  "a";   // (const char)[2]
  L"a";  // (const wchar_t)[2]

  10;    // int
  10u;   // unsigned int
  10L;   // long
  10uL;  // unsigned long
  012;   // int, восьмеричное число
  0xC;   // int, шестнадцатиричное число

  3.14;   // double
  3.14f;  // float
  3.14L;  // long double

  10;     // int
  10u;    // unsigned int
  10.;    // double
  10e-2;  // double
}