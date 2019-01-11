#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>c

using std::vector;

struct Segment {
  int start, end;
};

int minimum(vector<Segment> &segments){
  int minValue=segments[0].start;
  int minItem=0;
  int n = segments.size();

  bool sortSeg (Segment a, Segment b){
    return (a.start < b.start);
  }

  for (int i = 1; i < n; i++){
      if (segments[i].start < minValue){
        minValue = segments[i].start;
        minItem = i;
      }
  }
  return minItem;

      struct filestruct
    {
    	std::string setting;
    	int value;
    };

    bool SortHS( const filestruct& elem1, const filestruct& elem2 )
    {
    	return elem1.value > elem2.value;
    }

    void SortHS()
    {
    std::vector<filestruct> hslist;
    std::sort(hslist.begin(), hslist.end(), SortHS);
    }

}

vector<int> optimal_points(vector<Segment> &segments) {

  vector<int> points;

  for (size_t i = 0; i < segments.size(); ++i) {
    int min = minimum(segments);
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
    segments.erase(segments.begin()+min);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  int min = minimum(segments);
  std::cout << "min index: " << min << "\n";

  // vector<int> points = optimal_points(segments);
  // std::cout << points.size() << "\n";
  // for (size_t i = 0; i < points.size(); ++i) {
  //   std::cout << points[i] << " ";
  // }
}
