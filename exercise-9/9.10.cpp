// Упражнение 9.10. Каковы типы следующих четырех объектов?

#include <vector>

int main() {
  std::vector<int> v1;
  const std::vector<int> v2;

  // Тут будет ошибка кстати. Тип auto сначала стал ..::iterator, а потом после
  // запятой успел стать ::const_iterator, что ломает программу. В общем
  // мораль сего примера такова: при определении типа auto несколькими
  // пременными с помощью оператора запятая, последние должны иметь одинаковый
  // тип.

  auto it1 = v1.begin(),  // std::vector<int>::iterator.
      it2 = v2.begin();   // std::vector<int>::const_iterator.

  auto it3 = v1.cbegin(),  // std::vector<int>::const_iterator.
      it4 = v2.cbegin();   // std::vector<int>::const_iterator.
}