// Упражнение 15.24. Какие виды классов нуждаются в виртуальном деструкторе?
// Какие задачи должен выполнять вируальный деструктор?

// Как базовые, так и производные классы нуждаются в виртуальном диструкторе.
// Наличие виртуального диструктора в базовом обусловено в необходимости
// задейтсвования диструктора в производном в случае, если объект базового будет
// указывать на производный. То есть базовому нужно будет знать как удалить
// производный в случае удаления этого указателя (если это был указатель на
// динамически созданный объект).