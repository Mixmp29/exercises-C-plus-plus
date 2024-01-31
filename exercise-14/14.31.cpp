// Упражнение 14.31. В классе StrBlobPtr не определен конструктор копий,
// оператор присвоения и деструктор. Почему?

// Потому что все синтезируемые операторы управления справляются со своми
// задачами. Weak_ptr всего лишь связана с shared_ptr и его копирование или
// прямое уадаление указателя ничего не сломает.