#include <iostream>
#include <cassert>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n) {
    if (n <= 1){
      return (long long)n;
    }

    long long fib1 = 0;
    long long fib2 = 1;
    long long temp;

    for (int i=1; i<n; i++){
      temp = fib2;
      fib2 = fib1 + fib2;
      fib1 = temp;
    }

    return fib2;
}

// void test_solution() {
//     assert(fibonacci_fast(3) == 2);
//     assert(fibonacci_fast(10) == 55);
//
//     int fibfast;
//     int fibnaive;
//
//     for (int n = 0; n < 46; n++) {
//       fibfast = fibonacci_fast(n);
//       fibnaive = fibonacci_naive(n);
//
//       std::cout << "n: " << n << '\n';
//       std::cout << "fibonacci_fast: " << fibfast << "\n";
//       std::cout << "fibonacci_naive: " << fibnaive << "\n";
//
//       assert(fibfast == fibnaive);
//       std::cout << " " << '\n';
//     }
//
// }

int main() {
  int n;
  std::cin >> n;

  //std::cout << fibonacci_naive(n) << '\n';
  std::cout << fibonacci_fast(n) << '\n';
  //test_solution();

  return 0;
}
