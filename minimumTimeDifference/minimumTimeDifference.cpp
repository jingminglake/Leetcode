#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution{
public:
  int timeToInt(string s) {
    istringstream iss(s);
    string hour, minute;
    getline(iss, hour, ':');
    getline(iss, minute, ':');
    return 60 * stoi(hour) + stoi(minute);
  }
  
  int findMinDifference(vector<string>& timePoints) {
    int size = timePoints.size();
    if (size <= 1)
      return 0;
    vector<int> vec(size, 0);
    for (int i = 0; i < size; i++) {
      vec[i] = timeToInt(timePoints[i]);
    }
    sort(vec.begin(), vec.end());
    int ans = min(vec[size-1] - vec[0], vec[0] + 1440 - vec[size-1]);
    for (int i = 1; i < size; i++) {
      ans = min(ans, min(vec[i] - vec[i-1], vec[i-1] + 1440 - vec[i]));
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string ss[3] = {"23:59", "00:00", "11:11"};
  vector<string> vec(ss, ss+3);
  cout << s.findMinDifference(vec);
  cout << endl;
  return 0;
}
