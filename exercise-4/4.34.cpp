// Упражнение 4.34. С учетом определений переменных данного раздела объясните,
// какие преобразования имеют место в следующих выражениях:

int main() {
  char cval;
  int ival;
  float fval;
  double dval;

  if (fval)
    ;  // Из float в bool. Если fval не 0, то true, иначе false;

  dval = fval + ival;  // Преобразование int в float, а потом в double;

  dval + ival* cval;  // Преобразование char в int, потом в double;
}