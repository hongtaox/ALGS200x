#include <iostream>
#include <vector>
#include <time.h>

using std::vector;
using std::cin;
using std::cout;

int64_t MaxPairwiseProduct(const vector<int64_t>& numbers) {
  int64_t result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int64_t MaxPairwiseProductFast(const vector<int64_t>& numbers){
  int64_t result = 0;
  int n = numbers.size();
  int index1 = 0;
  for (int i = 1; i<n; i++){
    if (numbers[i] > numbers[index1]){
      index1 = i;
    }
  }
  int index2;
  if (index1 == 0) {
    index2 = 1;
  } else {
    index2 = 0;
  }
  for (int i = 1; i<n; i++){
    if (index1 != i && (numbers[i] > numbers[index2])){
      index2 = i;
    }
  }
  result = numbers[index1] * numbers[index2];
  return result;
}

int main() {
    srand (time(NULL));
    //stress test//
    bool test = true;
    while (test == true){
      int no = 10;
      cout << "number of elements"<< no << "\n";
      std::vector<int64_t> numTest(no);
      for (int i=0; i < no; i++){
        numTest[i]=rand()%100000;
        cout << numTest[i]<<"\n";
      }

      int64_t result = MaxPairwiseProductFast(numTest);
      cout << "The result is: "<< result << "\n";

      test = false;
    }
    //
    // int n;
    // cin >> n;
    // vector<int64_t> numbers(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> numbers[i];
    // }
    // int64_t result = MaxPairwiseProductFast(numbers);
    // //int64_t result = MaxPairwiseProduct(numbers);
    // cout << result << "\n";

    return 0;
}
