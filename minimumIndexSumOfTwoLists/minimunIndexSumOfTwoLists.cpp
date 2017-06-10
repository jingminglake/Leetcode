#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> ans;
    unordered_map<string, int> m;
    int size1 = list1.size();
    int size2 = list2.size();
    for (int i = 0; i < size1; i++) {
      m.insert(make_pair(list1[i], i));
    }
    unordered_map<string, int>::iterator it;
    int min = INT_MAX;
    for (int j = 0; j < size2; j++) {
      it = m.find(list2[j]);
      if (it != m.end()) {
	//cout << j + it->second << "---" << endl;
	if (j + it->second == min) 
	  ans.push_back(list2[j]);
	else if (j + it->second < min) {
	  ans.clear();
	  ans.push_back(list2[j]);
	  min = j + it->second;
	}
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string str1[5] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  string str2[3] = {"KFC", "Shogun", "Burger King"};
  vector<string> vec1(str1, str1+5);
  vector<string> vec2(str2, str2+3);
  vector<string> ans = s.findRestaurant(vec1, vec2);
  for (string ss : ans) {
    cout << ss << " ";
  }
  cout << endl;
  return 0;
}
