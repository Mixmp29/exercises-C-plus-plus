// Упражнение 4.8. Объясните, когда обрабатываются операнды операторов
// логического AND, логического OR и оператора равенства.

/* Все эти операторы левосторонние, то есть начинают обрабатываться слева.
 *
 * if (val1 && val2) // val2 обрабатывается тогда и только тогда, когда
 *                   // обработался val1 и он true.
 *
 * if (val1 || val2) // val2 обрабатывается тогда и только тогда, когда
 *                   // обработался val1 и он true.
 *
 * if (val1 == val2) // Обрабатываются оба выражения. Сначала в обработку идет
 *                   // val1, затем val2.
 */