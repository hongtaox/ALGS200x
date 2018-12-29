#include <iostream>
#include <cassert>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int128_t fibonacci_fast(int n) {
    if (n <= 1){
      return (int128_t)n;
    }

    int128_t fib1 = 0;
    int128_t fib2 = 1;
    int128_t temp;

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
