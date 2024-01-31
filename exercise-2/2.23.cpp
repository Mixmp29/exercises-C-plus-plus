/*

Упражнение 2.23. Есть указатель p, можно ли определить, указывает ли он на
допустимый объект? Если да, то как? Если нет, то почему?

Не совсем понимаю вопрос.

Если предположить, что указатель был объявлен, но не определён, а потом по нему
пытаются получить значение по адресу через оператор *, то:
Да. Попытка извлечь значение из адреса недопустимого объекта
приведёт к неопределённому поведению. Поэтому всегда стоит инициализировать
указатель в начале либо nullptr/0 или допустимым адресом другого значения.

Можно сделать проверку на то, указывает ли он на что-либо
  if (p) // Если в нём что-то есть, то условие будет True. Если в нём nullptr/0,
         // то False. Если адрес не определён, то бог в помощь вместе с
         // компилятор (может указывать на адрес где значение неопределено,
         // может быть непредсказуемое поведение)

 */