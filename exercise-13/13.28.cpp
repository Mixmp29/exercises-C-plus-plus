// Упражнение 13.28. С учетом следующих классов реализуйте стандартный
// конструкто и необходимые функции-члены управления копированием.

// Нужно всего лишь правильно передать все переменные-члены и указатели-члены.

#include <new>
#include <string>

class TreeNode {
 public:
  TreeNode(const std::string& s)
      : value(s), count(0), left(nullptr), right(nullptr) {}

  TreeNode(const TreeNode& rhs)
      : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {}

  ~TreeNode() {
    // В зависимости от реалиазации явный деструктор может не понадобиться, если
    // указатель на объект будет создан без использования динамической памяти.
    // Однако буду предполагать, что указатель был создан при помощь new и нужно
    // явно удалить объект по указателю.
    delete left;
    delete right;
  }

  TreeNode& operator=(const TreeNode& rhs) {
    // Сохранить правый операнд.
    TreeNode* newleft = rhs.left;
    TreeNode* newright = rhs.right;

    // Удалить леввый.
    delete left;
    delete right;

    // Перезаписать левый.
    value = rhs.value;
    count = rhs.count;
    left = newleft;
    right = newright;

    return *this;  // <- Переодически забываю эту штуку. Не надо так.
  }

 private:
  std::string value;
  int count;
  TreeNode* left;
  TreeNode* right;
};

// Возможно сделал неправильно. Если так, то доделаю.

class BinStrTree {
  BinStrTree(TreeNode* r = nullptr) : root(r) {}
  BinStrTree(const BinStrTree& rhs) : root(rhs.root) {}

  BinStrTree& operator=(const BinStrTree& rhs) {
    TreeNode* newroot = rhs.root;
    delete root;
    root = newroot;

    return *this;
  }

 private:
  TreeNode* root;
};