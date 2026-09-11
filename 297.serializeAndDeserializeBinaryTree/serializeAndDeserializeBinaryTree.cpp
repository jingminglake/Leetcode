#include <iostream>
#include <vector>
#include <queue>
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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t) {
                res += to_string(t->val) + " ";
                q.push(t->left);
                q.push(t->right);
            } else {
                res += "# ";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        istringstream iss(data);
        string node = "";
        iss >> node;
        TreeNode *res = new TreeNode(stoi(node));
        TreeNode *cur = res;
        queue<TreeNode*> q;
        q.push(cur);
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (!(iss >> node))
                break;
            if (node != "#") {
                cur = new TreeNode(stoi(node));
                q.push(cur);
                t->left = cur;
            }
            if (!(iss >> node))
                break;
            if (node != "#") {
                cur = new TreeNode(stoi(node));
                q.push(cur);
                t->right = cur;
            }
        }
        return res;
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
