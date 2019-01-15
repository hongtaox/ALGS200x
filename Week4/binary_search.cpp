#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using std::vector;

long long binary_search(const vector<long long> &a, long long x, long long l, long long r) {
  long long left = l;
  long long right = r;

  if (right < left){
    return (-1);
  }

  long long mid = abs (left +floor((right-left)/2));
  //std::cout << "x: "<< x << " left: " << left << " right: " << right << " mid: " << mid << " a[mid]: " << a[mid]<<"\n";

  if (a[mid]==x){
    //std::cout << "mid: " << mid << " x: " << x << "\n";
    return mid;
  }
  else if (a[mid]>x){
    return binary_search(a, x, left, mid-1);
  } else {
    return binary_search(a, x, mid + 1, right);
  }
}

long long linear_search(const vector<long long> &a, long long x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long long m;
  std::cin >> m;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  long long left = 0, right = (long long)a.size();
  for (long long i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], left, right) << ' ';
  }
}
