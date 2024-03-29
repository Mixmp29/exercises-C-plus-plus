// Упражнение 7.28. Что если бы в предыдущем упражнении типом возварщаемого
// значения функции move(), set() и display() был Screen, а не Screen&?

// В таком случае возвращалась бы копия объекта, которая инициализровала
// временный объект вызова типом возварщаемого значения Screen. В данном случае
// функция move успевала бы вносить изменения объекта myScreen,
// однако изменения в set() уже будут происходить с временным объектом, копия
// результата которого пойдет в display.

// То есть ход программы будет такой:
// Вызов move() объекта myScreen -> копия результата в set() ->
//                               -> копия результата в display().
// Но эта последовательность не изменит сам myScreen.