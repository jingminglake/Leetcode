// clang++ kthSmallestElementInASortedMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    struct compare
    {
        bool operator()(const tuple<int, int, int>& t1, const tuple<int, int, int>& t2)
        {
            return get<2>(t1) > get<2>(t2);
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, compare > pq;
        for (int i = 0; i < m; i++) {
            pq.push(make_tuple(i, 0, matrix[i][0]));
        }
        for (int a = 1; a < k; a++) {
            auto t = pq.top(); pq.pop();
            int i = get<0>(t);
            int j = get<1>(t);
            if (j + 1 >= n) continue;
            pq.push(make_tuple(i, j + 1, matrix[i][j + 1]));
        }
        return get<2>(pq.top());
    }
};

int main()
{
    Solution s;
    vector<int> row1 = {1,5,9};
    vector<int> row2 = {10,11,13};
    vector<int> row3 = {12,13,15};
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    cout << s.kthSmallest(matrix, 8);
    cout << endl;
    return 0;
}
