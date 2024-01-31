// Упражнение 4.35. С учетом определений

char cval;
int ival;
unsigned int ui;
float fval;
double dval;

// укажите неявные преобразования типов, если таковые вообще имеются.

int main() {
  cval = 'a' + 3;  // Преобразование char в int, потом обратно в char;

  fval = ui - ival * 1.0;  // Преобразование int в double, затем в unsigned int,
                           // а потом в float.

  dval = ui * fval;  // Преобразование unsigned int в float, а потом в double.

  cval = ival + fval + dval;  // Преобразование int -> float -> double -> char;
}