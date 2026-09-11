/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string res = to_string(root->val) + " " + to_string(root->children.size()) + " ";
        for (Node* c : root->children) {
            res += serialize(c);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        queue<string> q = split(data);
        return deserializeHelper(q);
    }
    
    Node* deserializeHelper(queue<string>& q) {
        if (q.empty()) return nullptr;
        int val = stoi(q.front()); q.pop();
        int num = stoi(q.front()); q.pop();
        Node* root = new Node(val);
        for (int i = 0; i < num; i++) {
            root->children.push_back(deserializeHelper(q));
        }
        return root;
    }
    
    queue<string> split(string data) {
        istringstream iss(data);
        queue<string> q;
        string str;
        while (getline(iss, str, ' ')) {
            q.push(str);
        }
        return q;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
