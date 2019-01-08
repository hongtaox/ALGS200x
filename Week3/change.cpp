#include <iostream>

int get_change(int m) {
  //initialize number of coins
  int n = 0;

  //how many 10 cents required
  n = m / 10;
  m = m % 10;

  //how many 5 cents required
  n = n + m / 5;
  m = m % 5;

  n = n + m;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
