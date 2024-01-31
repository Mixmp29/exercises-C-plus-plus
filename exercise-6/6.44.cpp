#include <string>

// Упражнение 6.44. Перепишите функцию isShorter() из раздела 6.2.2 (стр. 278)
// как встраиваемую.

inline bool isShorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}