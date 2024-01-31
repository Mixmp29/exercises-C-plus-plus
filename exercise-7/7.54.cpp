// Упражнение 7.54. Должны ли члены класса Debug, начинающиеся с set_ быть
// объявлени как constexpr? Если нет, то почему?

class Debug {
 public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

  constexpr bool any() { return hw || io || other; }

  // Нет, так как они не возвращают никакого значения, только меняют значения
  // переменных членов.
  void set_io(bool b) { io = b; }
  void set_hw(bool b) { hw = b; }
  void set_other(bool b) { hw = b; }

 private:
  bool hw;
  bool io;
  bool other;
};