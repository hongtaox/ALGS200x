#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

struct bounds{
  long long low;
  long long high;
};

//this function sorts
bounds partition2(vector<long long> &a, long long l, long long r) {
  //set pivot
  long long pivot = a[l];

  //set low and high bounds
  bounds lowhigh;
  long long low = l;
  long long high = r;

  long long i=1;
  //loop from polong long adlowacent to pivot until rightmost polong long
  while (i < high){
    if (a[i] < pivot){
      swap(a[i], a[low]);
      low++; i++;
    }
    else if (a[i] > pivot){
      swap(a[i], a[high]);
      high--;
    }
    else {
      i++;
    }
  }

  lowhigh.low = low;
  lowhigh.high = high;

  swap(a[l], a[low]);

  return lowhigh;
}

void randomized_quicksort(vector<long long> &a, long long l, long long r) {
  if (l >= r) {
    return;
  }

  long long pivot = l + rand() % (r - l + 1);
  swap(a[l], a[pivot]); //l is the new pivot

  bounds m = partition2(a, l, r);

  randomized_quicksort(a, l, m.low);
  randomized_quicksort(a, m.high, r);
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quicksort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
