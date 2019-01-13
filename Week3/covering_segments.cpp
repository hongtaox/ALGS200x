#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using std::vector;

struct Segment {
  int start, end;
};
bool sortSeg (const Segment &a, const Segment &b){
  return (a.end < b.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> results;

  std::sort(segments.begin(),segments.end(), sortSeg);
  int point = segments[0].end;
  results.push_back(point);
  for (size_t i = 0; i < segments.size(); ++i) {
    if (segments[i].start<=  point && point <= segments[i].end){
    }
    else{
      point = segments[i].end;
      results.push_back(point);
    }
  }
  return results;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
