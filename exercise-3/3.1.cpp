#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  // 1.9
  int sum = 0, val = 50;

  while (val < 100) {
    cout << sum << " + " << val << " = " << (sum += val) << endl;
    ++val;
  }

  cout << "Sum of 1 to 10 isclusive is " << sum << endl;

  // 1.10
  int val2 = 10;

  while (val2 > 0) {
    cout << val2 << endl;
    --val2;
  }

  // 1.11
  int left, right;

  cin >> left >> right;

  while (left <= right) {
    cout << left++ << endl;
  }

  // 2.41
  Sales_data data1, data2;
  double price;

  cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;

  cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;

  if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;

    cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

    if (totalCnt != 0) {
      cout << totalRevenue / totalCnt << endl;
    } else {
      cout << "(no sales)" << endl;
    }
  } else {
    cerr << "Data must refer to the same ISBN" << endl;
    return -1;
  }
}