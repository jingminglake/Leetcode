#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec{
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string res = to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
        return res;
    }
    TreeNode* deserialize(string data) {
        vector<int> nodes;
        istringstream iss(data);
        string str;
        while (getline(iss, str, ' ')) {
            nodes.push_back(stoi(str));
        }
        int index = 0;
        return deserializeHelper(nodes, index, INT_MAX, INT_MIN);
    }
    TreeNode* deserializeHelper(vector<int>& nodes, int& index, int maxV, int minV) {
        if (index == nodes.size())
            return nullptr;
        int val = nodes[index];
        if (val < minV || val > maxV)
            return nullptr;
        TreeNode *root = new TreeNode(val);
        index++;
        root->left = deserializeHelper(nodes, index, val, minV);
        root->right = deserializeHelper(nodes, index, maxV, val);
        return root;
    }
    void preorder(TreeNode* root) {
        if (!root)
            return;
        cout << root->val << " ";
        TreeNode *leftChild = root->left;
        TreeNode *rightChild = root->right;
        delete root;
        preorder(leftChild);
        preorder(rightChild);
    }
};

int main()
{
    int tree[7] = {5,3,6,2,4,9999,7};
    int size = sizeof(tree)/sizeof(tree[0]);
    vector<TreeNode *> vec;
    for (int i = 0; i < size; i++) {
        if (tree[i] != 9999) {
            vec.push_back(new TreeNode(tree[i]));
        } else {
            vec.push_back(NULL);
        }
    }
    for (int i = 0; i < size/2; i++) {
        if(!vec[i])
            continue;
        if (i*2 + 1 < size)
            vec[i]->left = vec[i*2 + 1];
        if (i*2 + 2 < size)
            vec[i]->right = vec[i*2 + 2];
    }
    Codec codec;
    TreeNode *t = codec.deserialize(codec.serialize(vec[0]));
    codec.preorder(t);
    for (TreeNode * tn : vec) {
        delete tn;
    }
    cout << endl;
    vec.clear();
    return 0;
}
