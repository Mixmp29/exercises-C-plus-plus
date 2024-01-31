// Упражнение 11.36. Текущая версия программы не повторяет допустимость входного
// файла. В частности, она подразумевает, что все правила в файле,
// преобразований корректны. Что будет, если строка в этом файле содержит ключ,
// один пробел и больше ничего? Проверьте свой ответ на текущей версии
// программы.

// Есть несколько развитий событий, в зависимости от ситуации.

// У программы есть минимальная проверка на допустимость входного файла. В
// случае, если будет записано правило, где на слово нет замены (есть ключ, нет
// значения), то программа выдаст ошибку о том, что нет правила, для такого
// слова.

// Это в случае, если есть ключ, пробел и больше ничего. Даже если будет просто
// ключ.

// Однако.

// Если это был последний ключ в правиле, то проверка не сработает из-за конца
// файла:
//  Если ключ без пробела, то выведется просто ключ.
//  Если ключ с двумя пробелами, то будет замена строки на пустую строку, ибо
//  size() > 1.

// Если есть один пробел, то ok, проверка сработает.