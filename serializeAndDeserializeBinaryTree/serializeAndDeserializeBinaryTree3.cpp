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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) return res;
        TreeNode* cur = root;
        queue<TreeNode*> q;
        q.push(cur);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
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
        vector<string> vec = splitBySpace(data);
        queue<string> q;
        for (string& s : vec) q.push(s);
        if (q.empty()) return nullptr;
        string val = q.front(); q.pop();
        queue<TreeNode*> q2;
        TreeNode* root = new TreeNode(stoi(val));
        q2.push(root);
        while (!q2.empty()) {
            TreeNode* t = q2.front(); q2.pop();
            if (q.empty()) break;
            string val = q.front(); q.pop();
            if (val != "#") {
                TreeNode* cur = new TreeNode(stoi(val));
                t->left = cur;
                q2.push(cur);
            }
            if (q.empty()) break;
            val = q.front(); q.pop();
            if (val != "#") {
                TreeNode* cur = new TreeNode(stoi(val));
                t->right = cur;
                q2.push(cur);
            }
        }
        return root;
    }
    
    vector<string> splitBySpace(string data) {
        vector<string> res;
        istringstream iss(data);
        string str;
        while (getline(iss, str, ' ')) {
            res.push_back(str);
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
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
