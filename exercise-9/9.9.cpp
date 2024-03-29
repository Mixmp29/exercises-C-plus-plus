// Упражнение 9.9. В чем разница между функциями begin() и cbegin()?

// Функция-член begin() возвращает ..::iterator или ..::const_iterator в
// зависимости от типа объекта. То есть имеется две перегруженные функции для
// неконстантного и константного варианта.

// Функция-член cbegin() возвращает только ..::const_iterator в любом случае.