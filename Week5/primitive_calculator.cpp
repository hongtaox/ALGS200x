#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int *getOperations (int index){
  int* numOperations = new int[index+1];
  //base_case
  numOperations[0]=0;
  numOperations[1]=0;
  numOperations[2]=1;
  numOperations[3]=1;

  int tempDivTwo;
  int tempDivThree;
  int tempMinOne;

  for (int i=4; i<=index; i++){

    tempMinOne = numOperations[i-1]+1;

    if (i%3==0 && ((numOperations[i/3]+1) <= tempMinOne)){
      numOperations[i] = numOperations[i/3]+1;
      //std::cout << "i: " << i << "min op: " << numOperations[i]<<": x3"<<"\n";
    }
    else if (i%2==0 && ((numOperations[i/2]+1) <= tempMinOne)){
      numOperations[i] = numOperations[i/2]+1;
      //std::cout << "i: " << i << "min op: " << numOperations[i]<<": x2"<<"\n";
    } else {
      numOperations[i] = tempMinOne;
      //std::cout << "i: " << i << "min op: " << numOperations[i]<< ": +1"<<"\n";
    }
  }

  return numOperations;
}

vector<int> optimal_sequence_dynamic(int n) {
  int* minOperations = getOperations(n);
  // work backwords with getOperations array
  std::vector<int> optimalSequence;
  optimalSequence.push_back(n);
  int i =n;

  while (i>1){

    if (i%3==0 && (minOperations[i]-minOperations[i/3])==1){
      optimalSequence.push_back(i/3);
      //std::cout << "i: " << i << "min op: " << minOperations[i]<<"\n";
      i=i/3;
    }
    else if (i%2==0 && (minOperations[i]-minOperations[i/2])==1){
      optimalSequence.push_back(i/2);
      //std::cout << "i: " << i << "min op: " << minOperations[i]<<"\n";
      i=i/2;
    } else {
      optimalSequence.push_back(i-1);
      //std::cout << "i: " << i << "min op: " << minOperations[i]<<"\n";
      i-=1;
    }

  }
  reverse(optimalSequence.begin(), optimalSequence.end());
  return optimalSequence;
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n > 2) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n = n / 3;
    } else if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  //vector<int> sequence = optimal_sequence_dynamic(n);
  vector<int> sequence = optimal_sequence_dynamic(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
