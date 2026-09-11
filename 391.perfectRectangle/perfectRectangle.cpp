#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.size() == 0 || rectangles[0].size() == 0)
            return false;
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        unordered_set<string> s;
        int area = 0;
        for (auto& rect : rectangles) {
            x1 = min (x1, rect[0]);
            y1 = min (y1, rect[1]);
            x2 = max (x2, rect[2]);
            y2 = max (y2, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            string s1 = to_string(rect[0]) + "," + to_string(rect[1]);
            string s2 = to_string(rect[0]) + "," + to_string(rect[3]);
            string s3 = to_string(rect[2]) + "," + to_string(rect[3]);
            string s4 = to_string(rect[2]) + "," + to_string(rect[1]);
            if (!s.count(s1))
                s.insert(s1);
            else 
                s.erase(s1);
            if (!s.count(s2))
                s.insert(s2);
            else 
                s.erase(s2);
            if (!s.count(s3))
                s.insert(s3);
            else 
                s.erase(s3);
            if (!s.count(s4))
                s.insert(s4);
            else 
                s.erase(s4);
        } // for
        string s1 = to_string(x1) + "," + to_string(y1);
        string s2 = to_string(x1) + "," + to_string(y2);
        string s3 = to_string(x2) + "," + to_string(y1);
        string s4 = to_string(x2) + "," + to_string(y2);
        if (!s.count(s1) || !s.count(s2) || !s.count(s3) || !s.count(s4) || s.size() != 4)
            return false;
        return area == (x2 - x1) * (y2 - y1);
    }
};

int main()
{
  Solution s;
  int a1[4] = {1,1,2,3};
  int a2[4] = {1,3,2,4};
  int a3[4] = {3,1,4,2};
  int a4[4] = {3,2,4,4};
  vector<int> vec1(a1, a1+4);
  vector<int> vec2(a2, a2+4);
  vector<int> vec3(a3, a3+4);
  vector<int> vec4(a4, a4+4);
  vector<vector<int> > rectangles;
  rectangles.push_back(vec1);
  rectangles.push_back(vec2);
  rectangles.push_back(vec3);
  rectangles.push_back(vec4);
  cout << s.isRectangleCover(rectangles);
  cout << endl;
  return 0;
}
