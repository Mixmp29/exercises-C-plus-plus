// Упражнение 14.51. Представьте последовательности преобразования (если они
// есть), необходимые для вызова каждой версии функции calc(), и объясните, как
// подпирается наилучшая подходящая функция.

struct LongDouble {
  LongDouble(double = 0.0);
  operator double();
  operator float();
};

void calc(int);
void calc(LongDouble);

int main() {
  double dval;
  calc(dval);  // Вызовет clac(int). // Выбор шел по принципам преобразований,
               // где преобразование в тип класса на последнем месте (стр 320).
}