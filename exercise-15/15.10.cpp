// Упражнение 15.10. Возвращаясь к обсуждению в разделе 8.1 (стр. 401),
// объясните, как работает программа на стр. 409, где функции read() класса
// Sales_data передавался объект ifstream.

// Поскольку ifstream наследован от istream можно использовать объекты ifstream,
// где предполагается взятие ссылки или указателя на объект istream. Все это
// работает через динамическое связывание (полиморфизм) или же виртуальный
// функции.