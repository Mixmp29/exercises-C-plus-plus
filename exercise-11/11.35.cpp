// Упражнение 11.35. Что будет (если будет) при таком изменении функции
// buildmap(): trans_map[key] = value.substr(1);
// заменить на trans_map.insert({key, value.substr(1)})?

// Такой insert просто пытается вставить элемент, но если он уже присутствует,
// то никак не меняет его. Однако, в этом случае менять значения не нужно.
// Правила по идее повторяться не должны, иначе замена работала бы некорректно.
// Следовательно менять старое значение по ключу не нужно и это вполне
// допустимое выражение.