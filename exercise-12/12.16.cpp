// Упражнение 12.16. Компиляторы не всегда предоставляют понятные сообщения об
// ошибках, если осуществляется попыка скопировать или присвоить указатель
// unique_ptr. Напишите программу, которая содержит эти ошибки, и посмотрите,
// как компилятор диагностирует их.

#include <memory>

int main() {
  std::unique_ptr<int> up(new int(5));
  std::unique_ptr<int> up1(up);  // Использование удаленной функции.
  std::unique_ptr<int> up2 = up;  // Использование удаленной функции.
}