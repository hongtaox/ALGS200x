#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

long long noPrize(long long n){
  //this function calculates no of prizes
  long long q;
  q = (-1 + sqrt(1+ 8 * n))/2;
  return q;
}

long long tri(long long n){
  //this function computes the triangle number based on no of prizes
  long long tri;
  tri = n*(n+1)/2;
  return tri;
}

long long term(long long n){
  //this calulcates the term based on the triangle numbers pattern
  long long t;
  t = n % tri(noPrize(n));
  return t;
}

vector<long long> optimal_summands(long long n) {
  vector<long long> summands;
  long long prizes = noPrize(n);
  long long candies=0;
  long long t = term(n);
  if (n<=2){
    summands.push_back(n);
    return summands;
  }
  for (int i=0; i < (prizes-1); i ++){
    candies ++;
    summands.push_back(candies);
  }
  summands.push_back(candies+t+1);
  return summands;
}

int main() {
  long long n;
  std::cin >> n;
  // std::cout << "x: "<< noPrize(n) << "\n";
  // std::cout << "tri: "<< term(n) << "\n";
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
