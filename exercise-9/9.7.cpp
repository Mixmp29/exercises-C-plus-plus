// Упражнение 9.7. Какой тип следует использовать в качестве индекса для вектора
// целых чисел?

// Если посмотреть реализацию оператора индексирования '[]' вектора, то типом
// параметра будет size_t. Следовательно этот тип и нужно использовать.

// Если не рассмотривать этот оператор, то можно использовать итератор.
// std::vector<int>::iterator.