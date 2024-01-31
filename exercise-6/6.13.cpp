// Упражнение 6.13. Если Т - имя типа, объясните различие между функцией,
// объявленной как void f(T) и void f(T&).

/* void f(T). Параметр этой функции инициалилзируется копией передаваемого
 * аргумента.

   void f(T&). Параметр этой функции связывается ссылкой с передаваемым
 аргументоам. Копирования в этом случае не происходит, можно обойти ненужные
 операции и сэкономить ресурсы памяти таким образом. Ссылки можно делать также
 на контейнеры: string, vector, ...*/