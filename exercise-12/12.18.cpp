// Упражнение 12.18. Почему класс указателя shared_ptr не имеет фукнции члена
// release()?

// У него как минимум есть get(). Функция release() зануляет счетчик умного
// указателя. Следовательно, для shared_ptr это означает, что объек будет удален
// у всех указывающих на него указателей раньше времени.