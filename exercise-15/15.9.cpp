// Упражнение 15.9. Когда может возникнуть отличие статического типа выражение
// от динамического типа? Приведите три примера, в которых статический и
// динамический типы отличаются?

// 1) В случае, когда происходит динамическое связывание (полиморфизм).

// 2,3) Преобразование из одного типа в другой. Базовый в производный или
// производный в базовый через dynamic_cast и static_cast соответственно.