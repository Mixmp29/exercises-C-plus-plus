// Упражнение 7.30. Обращение к членам класса при помощи указателя this вполне
// допустимо, но избыточно. Обсудите преимущества и недостатки явного
// использования указателя this для доступа к членам.

/* Явное использование помощет различать переменные-члены и локальные переменные
 * самой функции-члена. Может помочь, если функция станет громадной, но
 * ценой этого будет написание не очень удобно читаемого кода. Лучше всего
 * использовать этот указатель по необходимости. К примеру возвращения объекта
 * из функции (либо его адреса). */