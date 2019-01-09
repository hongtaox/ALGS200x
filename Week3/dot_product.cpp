#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int maximum(vector<long long> c){
  long long maxValue=0;
  long long maxItem=0;
  int n = c.size();

  for (int i = 0; i < n; i++){
      if (c[i] > maxValue){
        maxValue = c[i];
        maxItem = i;
      }
  }
  return maxItem;
}

long long max_dot_product(vector<long long> a, vector<long long> b) {
  int n = a.size();
  int best_a = 0;
  int best_b = 0;
  long long result = 0;

  for (int i = 0; i < n; i++){
    //calculate best value
    best_a = maximum(a);
    best_b = maximum(b);
    // cout << "a[" << i<< "]: " << a[best_a] << "\n";
    // cout << "b[" << i<< "]: " << b[best_b] << "\n";
    // cout << "n: " <<  a.size() << "\n";

    result += ((long long) a[best_a]) * b[best_b];

    a.erase(a.begin()+best_a);
    b.erase(b.begin()+best_b);
  }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
