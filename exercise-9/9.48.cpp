// Упражнение 9.48. С учетом определения переменных name и numbers на стр. 469,
// что возвращает вызов функции numbers.find(name)?

// В данном случае будет возвращено std::string::npos, так как подстрока name не
// содержит полного соответствия в number. Если бы использовался
// find_first_of(name), то вернулся бы индекс 2. При find_last_of(name) также 2.