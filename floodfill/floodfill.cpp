#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
    vector<vector<int> > res;
    if (image.size() == 0)
      return res;
    if (image[sr][sc] != newColor)
      dfs(image, sr, sc, newColor, image[sr][sc]);
    return image;
  }
  void dfs(vector<vector<int> >& image, int sr, int sc, int newColor, int oldColor) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor)
      return;
    image[sr][sc] = newColor;
    dfs(image, sr + 1, sc, newColor, oldColor);
    dfs(image, sr - 1, sc, newColor, oldColor);
    dfs(image, sr, sc + 1, newColor, oldColor);
    dfs(image, sr, sc - 1, newColor, oldColor);
  }
};

int main()
{
  Solution s;
  vector<vector<int> > image;
  vector<int> r1 = {0, 0, 0};
  vector<int> r2 = {0, 1, 1};
  //vector<int> r3 = {1, 0, 1};
  image.push_back(r1);
  image.push_back(r2);
  //image.push_back(r3);
  vector<vector<int> > res = s.floodFill(image, 1, 1, 1);
  for (vector<int>& vec : res) {
    for (int p : vec) {
      cout << p << " ";
    }
    cout << endl;
  }
  return 0;
}
