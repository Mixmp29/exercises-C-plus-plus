// Упражнение 6.21. Напишите функцию, получающую значение типа int и указатель
// на int, а возвращающую значение типа int, если оно больше, или значение, на
// которое указывает указатель, если больше оно. Какой тип следует использовать
// для указателя?

// Для указателя следует использовать тип указателя на константу, так мы точно
// гарантируем, что значение по адресу никак не будет изменяться. Параметр 'a'
// локатльная переменная, она удалится по окончании работы функции. В функции
// она никак не меняется, поэтому от себя поставил ее const.
int max(const int a, const int* b) { return (a >= *b) ? a : *b; }