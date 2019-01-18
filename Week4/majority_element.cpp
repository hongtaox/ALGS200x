#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long r_binary_search(const vector<long long> &a, long long left, long long right, long long x, long long n) {

  if (right < left){
    return (-1);
  }

  long long mid = abs (left + (right-left)/2);
  //std::cout << "x: "<< x << " left: " << left << " right: " << right << " mid: " << mid << " a[mid]: " << a[mid]<<"\n";

  if ((mid == n || x < a[mid+1]) && a[mid]==x){
    //std::cout << "mid: " << mid << " x: " << x << "\n";
    return mid;
  }
  else if (x<a[mid]){
    return r_binary_search(a, left, mid - 1, x, n);
  } else {
    return r_binary_search(a, mid +  1, right, x, n);
  }

  return -1;
}

long long l_binary_search(const vector<long long> &a, long long left, long long right, long long x, long long n) {

  if (right < left){
    return (-1);
  }

  long long mid = abs (left + (right-left)/2);
  //std::cout << "x: "<< x << " left: " << left << " right: " << right << " mid: " << mid << " a[mid]: " << a[mid]<<"\n";

  if ((mid == 0 || x > a[mid-1]) && a[mid]==x){
    // std::cout << "mid: " << mid << " x: " << x << "\n";
    return mid;
  }
  else if (x>a[mid]){
    return l_binary_search(a, mid +  1, right, x, n);
  } else {
    return l_binary_search(a, left, mid - 1, x, n);
  }
  return -1;
}

long long get_majority_element(vector<long long> &a, long long left, long long right) {
  long long mid = abs (left +(right-left)/2);

  long long leftMax, rightMax;
  leftMax = l_binary_search(a, left, mid-1, a[mid], a.size()-1);
  //std::cout << "leftMax: " << leftMax <<  " at left: "<<left<<"\n";
  rightMax = r_binary_search(a, mid+1, right, a[mid], a.size()-1);
  //std::cout << "rightMax: " << rightMax << " at right: "<<right<<"\n";
  //std::cout << "\n";

  if (leftMax == -1){
    leftMax = mid;
  }
  if (rightMax == -1){
    rightMax = mid;
  }
  if ((rightMax - leftMax + 1) > mid) {
    // std::cout<<"leftMax: " << leftMax<< "\n";
    // std::cout<<"rightMax: " << rightMax<< "\n";
    // std::cout << "rightMax - leftMax: "<< rightMax - leftMax +1 << " mid: "<<mid<<"\n";
    return a[mid];
  }
  else {
    return -1;
  }

  return -1;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  //std::cout << get_majority_element(a, 0, a.size()) << '\n';
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
