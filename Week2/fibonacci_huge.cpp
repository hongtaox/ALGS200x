#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long getPi(long long m){
  // this function calculates the Pisiano Period for the Fibonacci Sequence
  long long temp = 0;
  long long previous  = 1;
  long long current;

  int i = 0;

  while (previous != 0 || temp != 1){
    //calculate Fn
    current = (temp + previous) % m;
    temp = previous;
    previous = current;
    i ++;
  }
  return i+1;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
  //this function returns Fn % m

  // define period
  long long pi = getPi(m);

  //calculate the term of period actually needed
  n = n % pi;

  //caclulate fibonacci of that term
  if (n <= 1){
    return n;
  }

  long long fib1 = 0;
  long long fib2 = 1;
  long long temp;

  for (int i=1; i<n; i++){
    temp = fib2;
    fib2 = (fib1 + fib2) % m;
    fib1 = temp;
  }

  return fib2 % m;

  }

// long long getDigits(int m){
//   long long previous = 0;
//   long long current  = 1;
//   cout << "\n";
//   cout << current % m << "\n";
//
//   for (long long i = 0; i < 50; ++i) {
//       long long tmp_previous = previous;
//       previous = current;
//       current = tmp_previous + current;
//       cout << current % m<< "\n";
//   }
//   return 1001;
// }

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

    // std::cin >> m;
    // std::cout << getDigits(m) << '\n';

    //std::cin >> m;
    //std::cout << getPi(m) << '\n';

}
