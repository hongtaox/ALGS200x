#include <iostream>
#include <time.h>
#include <assert.h>
#include <ctime>
using namespace std;

long long lcm_naive(int a, int b) {
  clock_t t;
  t = clock();
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0){
      t = (clock() - t)/1000;
      cout << "Naive: " <<"It took " << t << " seconds long." << "\n";
      return l;
    }
  t = (clock() - t)/1000;
  cout << "Naive: " <<"It took " << t << " seconds long." << "\n";
  return (long long) a * b;
}

int gcd_fast(int a, int b){
  if (b == 0 ){
    return a;
  }
  a = a % b;
  return gcd_fast(b,a);
}

long long lcm_fast(int a, int b){
  //initialize clock
  //clock_t t;
  //t = clock();
  long long ab;
  ab = (long long) a * b / gcd_fast(a, b);

  //print values
  //cout << "a * b: " << (long long) a * b  << " ab : "<<ab<< "\n";
  //print time
  //t = (clock() - t)/1000;
  //cout << "Fast: " <<"It took " << t << " seconds long." << "\n";

  return ab;
}

// void testComp(){
//   srand (time(NULL));
//   int a;
//   int b;
//   long long naive;
//   long long fast;
//
//   //do 100 iterations of tests for random inputs
//   for (int i = 0; i < 100; i++){
//     //random a and b ranging from 1 to 2*10^9
//     a = rand()%10000 + 1;
//     b = rand()%10000 + 1;
//
//     //run both functions
//     naive = lcm_naive(a,b);
//     fast = lcm_fast(a,b);
//
//     //print and assert statement
//     cout << "a: " << a << " b: " << b << "\n";
//     cout << "naive: " << naive << " fast: " << fast << "\n";
//     assert(naive==fast);
//     cout << "\n";
//   }
// }
//
// void testSolo(){
//   srand (time(NULL));
//   int a;
//   int b;
//   long long fast;
//   clock_t t;
//
//   //do 100 iterations of tests for random inputs
//   for (int i = 0; i < 100; i++){
//     //random a and b ranging from 1 to 2*10^9
//     a = rand()%1000000 + 1;
//     b = rand()%1000000 + 1;
//
//     t = clock();
//     fast = lcm_fast(a,b);
//     t = (clock() - t)/1000;
//
//     //print and assert statement
//     cout << "iter no: "<< i <<" a: " << a << " b: " << b << "\n";
//     cout << " fast: " << fast << "\n";
//     cout << "\n";
//
//     //run function and time check
//     cout << "Fast: " <<"It took " << t << " seconds long." << "\n";
//     if (t>0){
//       cout << "ERROR: too slow" << "\n";
//     }
//   }
// 
// }

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;

  //testComp();
  //testSolo();

  return 0;
}
