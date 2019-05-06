#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  int noOfSouv = A.size();
  int si;
  int sum = 0;
  int target;
  int temp;
  int iter = 0;

  for (int i = 0; i < noOfSouv; i++){
    sum += A[i];
  } q

  if (noOfSouv < 3){
    return 0;
  }

  if (sum % 3 == 0){
    target = sum/3;
  }
  else {
    return 0;
  }

  int m = target + 1;
  int n = noOfSouv + 1;

  int **value;
  value = new int*[m];
  for (int i = 0; i < m; i++){
    value[i] = new int[n];
  }

  for (int i = 0; i < m; i++){
    value[i][0] = 0;
  }

  for (int i = 0; i < n; i++){
    value[0][i] = 0;
  }

  for (int j = 1; j < n; j++){
    si=A[j-1];
    for (int i = 1; i < m; i++){
      value[i][j] = value[i][j-1];
      if (si <= i){
        temp = value[i-si][j-1] + si;
        if (temp > value[i][j]){
          value[i][j] = temp;
        }
        if (value[i][j] == target){
          iter ++;
        }
      }
    }
  }

  if (iter < 3){
    return 0;
  } else {
    return 1;
  }
  //delete [] sharing;
  return target;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
