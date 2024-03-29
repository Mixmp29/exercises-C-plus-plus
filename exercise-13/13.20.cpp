// Упражнение 13.20. Объясните, что происходит при копировании, присвоении и
// удалении объектов класса TextQuery и QueryResult из раздела 12.3 (стр. 617).

// У TextQuery копируются указатель file на объект и элементы карты, которые
// имеют тип pair. Умные указатели приростят свои счетчики и будут указывать на
// одни и те же области видимости в разных объектах. Это происхоидть как и для
// инициализации копированием, так и для оператора присвоения. Деструктор будет
// освобождать элементы как надо во всех случая, даже умные указатели, так как
// класс shared_ptr сам освобождает объект при остутствии на него указателей.

// Всё тоже самое в случае QueryResult.