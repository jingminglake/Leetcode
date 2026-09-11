#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0)
            return 0;
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<int> dp(n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1)
                    dp[j] = triangle[i][j];
                else if (j + 1 < n)
                    dp[j] = min (dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    int a1[1] = {2};
    int a2[2] = {3,4};
    int a3[3] = {6,5,7};
    int a4[4] = {4,1,8,3};
    vector<int> vec1(a1, a1+1);
    vector<int> vec2(a2, a2+2);
    vector<int> vec3(a3, a3+3);
    vector<int> vec4(a4, a4+4);
    vector<vector<int> > triangle;
    triangle.push_back(vec1);
    triangle.push_back(vec2);
    triangle.push_back(vec3);
    triangle.push_back(vec4);
    cout << s.minimumTotal(triangle);
    cout << endl;
    return 0;
}
