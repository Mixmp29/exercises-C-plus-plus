// Упражнение 7.39. Допустимо ли для конструктора, получающего строку, и
// конструктора, получающего istream&, иметь аргументы по умолчанию, если нет,
// то почему?

// Нет, иметь у обоих этих конструктора значение по умолчанию ОДНОВРЕМЕННО
// нельзя, так как это будет перегрузка с неоднозначным выбором. Оба этих
// конструктора могут не получить аргумент и компилятор не сможет выбрать одну
// из них. Уровень лучшего варианта будет одинаковый.

// По отдельности - пожалуйста.