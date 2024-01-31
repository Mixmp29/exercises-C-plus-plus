// Упражнение 7.25. Может ли класс Screen безопасно полагаться на заданные по
// умолчанию версии операторов копирования и присвоения? Если да, то почему?
// Если нет, то почему?

/* Да, безопасно. В книге еще не объяснили про использование ресурсов для
 * динамической памяти, но уже дали понять, что копирование, присвоение и
 * удаление в коллекциями типа vector и string работают нормально без всяких
 * огрехов. Остальные переменные-члены должны также нормально работать.*/