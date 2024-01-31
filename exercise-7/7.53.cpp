// Упражнение 7.53. Определите собственную версию класса Debug.

class Debug {
 public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

  constexpr bool any() { return hw || io || other; }
  void set_io(bool b) { io = b; }
  void set_hw(bool b) { hw = b; }
  void set_other(bool b) { hw = b; }

 private:
  bool hw;  // аппаратная ошибка, отличная от ошибки IO
  bool io;     // ошибка IO
  bool other;  // другие ошибки
};