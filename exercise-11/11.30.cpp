// Упражнение 11.30. Объясните значение операнда pos.first->second,
// использованного в выражении вывода последней программы данного раздела.

// Переменной pos была присвоена пара итераторов pair<iter_beg, iter_end>,
// которые обозначали диапазон значений по искомому ключу.

// Выражение pos.first->second обращалась к переменной-члену значения итератора,
// которая выводилась на стандартное устройство вывода.