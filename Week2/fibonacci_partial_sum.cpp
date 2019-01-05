#include <iostream>
#include <vector>
using std::vector;
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to){

      //find new n (since the period of modulus 10 is 60)
      long long pi = 60;
      to = to % pi;
      from  = (from % pi) - 1;
      if (from == -1 ){
        from = 0;
      }

      long long fib1;
      long long fib2;
      long long sum1;
      long long sum2;
      long long temp;

      if (from <= 1){
        sum1 = from;
      }
      else{
        fib1 = 0;
        fib2 = 1;
        sum1 = fib1 + fib2;

        for (int i=1; i<from; i++){
          temp = fib2;
          fib2 = (fib1 + fib2) % 10;
          fib1 = temp;
          sum1 += fib2;
        }
      }

      if (to <= 1 ){
        sum2 = to;
      }
      else {
        fib1 = 0;
        fib2 = 1;
        sum2 = fib1 + fib2;

        for (int i=1; i<to; i++){
          temp = fib2;
          fib2 = (fib1 + fib2) % 10;
          fib1 = temp;
          sum2 += fib2;
        }
      }

      return (sum2 - sum1) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
