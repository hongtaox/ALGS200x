#include <iostream>
#include <vector>

int get_change(int m) {
  //The minimum number of coins with denominations 1,3,4 that changesmoney

  int coins [3] = {1, 3, 4};
  int minChange[m + 1];
  int tempChange;

  //base case
  minChange[0] = 0;

  //initalize to maximum value
  for (int i =1; i <m+1; i++){
    minChange[i] = m;
    for (int j=0; j<3; j++){
      if (i >= coins[j]){
        tempChange = minChange[i-coins[j]]+1;
        if (tempChange < minChange[i]){
          minChange[i] = tempChange;
        }
      }
    }
  }
  return minChange[m];
}

int main() {
  int m;

  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
