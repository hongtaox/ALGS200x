#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

double bestValue(vector<int> weights, vector<int> values){
  double maxValuePerWeight=0;
  double bestItem=0;
  int n = weights.size();
  cout << "n: " << n << "\n";

  for (int i = 0; i < n; i++){
    if (weights[i]  > 0){
      if (values[i]/weights[i] > maxValuePerWeight){
        maxValuePerWeight = values[i]/weights[i];
        cout << "maxValuePerWeight: " << maxValuePerWeight << "\n";
        bestItem = i;
        cout << "bestItem: " << bestItem << "\n";
      }
    }
  }
  cout << "final bestItem: " << bestItem << "\n";
  return bestItem;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  double best = 0.0;
  double min = 0.0;
  vector <int> amounts(n,0);

  //xlooping n times
  for (int i = 0; i < n; i++){
    if (capacity==0){
      return value;
    }

    //calculate best value
    best = bestValue(weights, values);
    min = min(capacity, weights[best]) //determinal  amount

    //calculate value
    value = value + min * (values[best]/weights[best]);
    weights[best] = weights[best] - best; //update weight
    amounts[best] = amounts[best] + min; //amount amount taken in for weight[best]
    capacity = capacity - best; //update capacity
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);


  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  cout << "\n";
  cout << "best value: "<< optimal_value) << "\n";

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}
