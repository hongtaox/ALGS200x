#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b){
  if (b == 0 ){
    return a;
  }
  a = a % b;
  return gcd_fast(b,a);
}

void test(){
  srand (time(NULL));
  int a;
  int b;
  int naive;
  int fast;

  //do 100 iterations of tests for random inputs
  for (int i = 0; i < 100; i++){
    //random a and b ranging from 1 to 2*10^9
    a = rand()%2000000000 + 1;
    b = rand()%2000000000 + 1;

    //run both functions
    naive = gcd_naive(a,b);
    fast = gcd_fast(a,b);

    //print and assert statement
    cout << "a: " << a << " b: " << b << "\n";
    cout << "naive: " << naive << " fast: " << fast << "\n";
    assert(naive==fast);
    cout << "\n";
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;

  //test();
  return 0;
}
