#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        return root;
    }
};

int main()
{
    Solution s;
    int tree[7] = {1,2,3,4,5,6,7};
    vector<int> nums(tree, tree+7);
    TreeNode* root = s.sortedArrayToBST(nums);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *t = q.front();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            cout << t->val << " ";
            q.pop();
            delete t;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
