#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int size = timeSeries.size();
    if (size == 0)
      return 0;
    int totalDamage = duration;
    int prevPoisonedTime = timeSeries[0];
    bool isPoisoned = true;
    for (int i = 1; i < size; i++) {
      /*if (!isPoisoned) {
	isPoisoned = true;
	continue;
	}*/
      if (timeSeries[i] - prevPoisonedTime < duration) {
	totalDamage += timeSeries[i] - prevPoisonedTime;
        //continue;
      } else {
	totalDamage += duration;
	//isPoisoned = false;	
      }
      prevPoisonedTime = timeSeries[i];
    }
    /* if (isPoisoned)
       totalDamage += duration;*/
    return totalDamage;
  }
};

int main()
{
  Solution s;
  int a[2] = {1,2};
  vector<int> vec(a, a+2);
  cout << s.findPoisonedDuration(vec, 2);
  cout << endl;
  return 0;
}
