#include <iostream>

int64_t get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int64_t previous = 0;
    int64_t current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int64_t tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1){
      return n;
    }

    int fib1 = 0;
    int fib2 = 1;
    int temp;

    for (int i=1; i<n; i++){
      temp = fib2;
      fib2 = (fib1 + fib2) % 10;
      fib1 = temp;
      //std::cout << "fib2: " << fib2 << '\n';
    }

    return fib2 % 10;
}

void test_solution() {
    int fibfast;
    int fibnaive;

    //assert(get_fibonacci_last_digit_fast(10000000) == get_fibonacci_last_digit_naive(10000000));

    for (int n = 1; n < 100; n++) {
      fibfast = get_fibonacci_last_digit_fast(n);
      //fibnaive = (int)get_fibonacci_last_digit_naive(n);

      std::cout << "n: " << n << '\n';
      std::cout << "get_fibonacci_last_digit_fast: " << fibfast << "\n";
      //std::cout << "get_fibonacci_last_digit_naive: " << fibnaive << "\n";
      //assert(fibfast == fibnaive);
      std::cout << " " << '\n';
    }
}

int main() {
    int n;
    std::cin >> n;
    // int naive = get_fibonacci_last_digit_naive(n);
    // std::cout << "naive: " "<< naive << '\n'

    int fast = get_fibonacci_last_digit_fast(n);
    std::cout << fast << '\n';;

    //test_solution();
    }
