#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int bestValue(vector<double> weights, vector<double> values){
  double maxValuePerWeight=0;
  double bestItem=0;
  int n = weights.size();

  for (int i = 0; i < n; i++){
    if (weights[i]  > 0){
      if (values[i]/weights[i] > maxValuePerWeight){
        maxValuePerWeight = values[i]/weights[i];
        bestItem = i;
      }
    }
  }
  return bestItem;
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  int n = weights.size();
  double best = 0.0;
  double w = 0.0;

  //looping n times
  for (int i = 0; i < n; i++){
    if (capacity==0){
      return value;
    }
    //calculate best value
    best = bestValue(weights, values);
    w = min(capacity, weights[best]); //determine  amount

    //calculate value
    value = value + (w * (values[best]/weights[best]));
    weights[best] = weights[best] - w; //update weight
    capacity = capacity - w; //update capacity
  }

  return value;
}

int main() {
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);

  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  long double optimal_value = get_optimal_value(capacity, weights, values);
  cout << fixed << showpoint;
  cout.precision(4);
  cout << optimal_value << std::endl;
  return 0;
}
