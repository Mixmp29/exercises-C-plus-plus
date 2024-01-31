// Упражнение 7.47. Объясните, должен ли быть явным конструктором Sales_data(),
// получающий строку. Каковы преимущества объявления конструктора явным? Каковы
// недостатки?

/* Смотря как делать реализацию. Именно в этом случае думаю стоило бы сделать
 * конструктор явным, чтобы не вводить пользователей в заблуждение. В таком
 * случае пользователи обязываются делать явное преобразование. Вряд ли оно
 * будет необходимо часто.
 *
 * Плюсы.
 * Ограждение пользователей от использования класса с неявными
 * преобразованиями. Если нужно можно делать явное преобразование, что
 * поспособствует пониманию кода и ограждению допущения ошибок.
 *
 * Минусы.
 * В зависимости  реализации класса явное преобразование может быть
 * утомительным в написании. Особенно, если запись этого типа очень большая.
 * Или если нужно часто использовать преобразование, что тоже утомительно писать
 * руками. К примеру const char* в string.
 * */