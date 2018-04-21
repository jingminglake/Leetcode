#include <iostream>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), Compare());
        vector<pair<int, int> > res;
        for (auto& p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<pair<int, int> > people = {make_pair(7,0), make_pair(4,4), make_pair(7,1), make_pair(5,0), make_pair(6,1), make_pair(5,2)};
    for(auto p : s.reconstructQueue(people))
        cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
    return 0;
}
