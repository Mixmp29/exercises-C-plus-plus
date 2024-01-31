// Упражнение 13.12. Сколько вызовов деструктора происходит в следующем
// фрагменте кода?

/*

bool fcn(const Sales_data *trans, Sales_data accum){
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
}

3 раза. Будет вызван деструктор accum, item1 и item2. trans был указателем,
вызова деструктора объекта, на который он указывает не будет.

 */