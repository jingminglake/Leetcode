//clang++ maximumXORofTwoNumbersInAnArrayII.cpp -std=c++11
#include <iostream>
#include <vector>
using namespace std;
class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
    TrieNode* next[2];
    ~TrieNode() {
        delete next[0];
        delete next[1];
    }
};

class Solution {
public:
    TrieNode *root;
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty())
            return 0;
        root = new TrieNode();
        for (int num : nums) {
            insert(num);
        }
        int res = INT_MIN;
        for (int num : nums) {
            TrieNode *cur = root;
            int compelentNum = 0;
            for (int i = 31; i >= 0; i--) {
                int curBit = (num >> i) & 1;
                if (cur->next[curBit ^ 1]) {
                    compelentNum += (1 << i);
                    cur = cur->next[curBit ^ 1];
                } else {
                    cur = cur->next[curBit];
                }
            }
            res = max (res, compelentNum);
        }
        delete root;
        return res;
    }
    void insert(int num) {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; i--) {
            int curBit = (num >> i) & 1;
            if (cur->next[curBit] == nullptr)
                cur->next[curBit] = new TrieNode();
            cur = cur->next[curBit];
        }
    }
};

int main(void)
{
    Solution s;
    vector<int> nums = {3,10,5,25,2,8};
    cout << s.findMaximumXOR(nums) << endl;
    return 0;
}
