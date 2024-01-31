// 2.7. Какие значения представляют эти литералы? Какой тип имеет каждый из них?
int main() {
  "Who goes with F\145rgus?\012";  // "Who goes with Fergus?\n" (const char)[23]

  3.14e1L;  // long double

  1024f;  // нет такого переопределения из int в float (как минимум суффиксами)

  3.14L;  // long double
}
