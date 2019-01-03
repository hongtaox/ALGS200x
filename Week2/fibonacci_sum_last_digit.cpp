#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci_sum_fast(long long n) {

    //find new n (since the period of modulus 10 is 60)
    long long pi = 60;
    n = n % pi;

    //find sum of fibonacci sequence
    if (n <= 1){
      return n;
    }

    long long fib1 = 0;
    long long fib2 = 1;
    long long sum = fib1 + fib2;
    long long temp;

    for (int i=1; i<n; i++){
      temp = fib2;
      fib2 = (fib1 + fib2) % 10;
      fib1 = temp;
      sum += fib2;
    }

    return sum % 10;
}

void test(){
  srand (time(NULL));
  int n;
  int naive;
  int fast;

  //do 100 iterations of tests for random inputs
  for (int i = 0; i < 100; i++){
    //random a and b ranging from 1 to 500
    n = rand()%50 + 1;

    //run both functions
    naive = fibonacci_sum_naive(n);
    fast = fibonacci_sum_fast(n);

    //print and assert statement
    cout << "n: " << n << "\n";
    cout << "naive: " << naive << " fast: " << fast << "\n";
    assert(naive==fast);
    cout << "\n";
  }
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << "\n";
    std::cout << fibonacci_sum_fast(n) << "\n";

    //test();
}
