#include <iostream>
#include <vector>
#include <time.h>

using std::vector;
using std::cin;
using std::cout;

int64_t MaxPairwiseProductNaive(const vector<int64_t>& numbers) {
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

void stressTest(int N, int64_t max){
  srand (time(NULL));
  bool test = true;
  while (test == true){
    int no = N;
    std::vector<int64_t> numTest(no);
    cout<<"\n";
    for (int i=0; i < no; i++){
      numTest[i]=rand()%max;
      cout << numTest[i]<< "\t";
    }
    cout<<"\n";

    int64_t resultFast = MaxPairwiseProductNaive(numTest);
    int64_t resultNaive = MaxPairwiseProductFast(numTest);

    if (resultFast == resultNaive){
      cout << "OK" << '\n';
      test = true;
    }
    else {
      cout<< "FAILURE" << '\n';
      cout << "resultFast: " <<resultFast<<"resultNaive: " <<resultNaive<<'\n';
      test = false;
    }
  }
}

int main() {

  // //stress test
  // int no;
  // int64_t max;
  // cin >> no;
  // cin >> max;
  // stressTest(no,max);

    int n;
    cin >> n;
    vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    int64_t result = MaxPairwiseProductFast(numbers);
    //int64_t result = MaxPairwiseProduct(numbers);
    cout << result << "\n";

    return 0;
}
