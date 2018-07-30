class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty())
            q.emplace(v1.begin(), v1.end());
        if (!v2.empty())
            q.emplace(v2.begin(), v2.end());
    }

    int next() {
        int res = -1;
        if (hasNext()) {
            auto p = q.front();
            if (p.first + 1 != p.second) {
                q.emplace(p.first + 1, p.second);
            }
            res = *p.first;
            q.pop();
        }
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
    queue<pair<vector<int>::iterator, vector<int>::iterator> > q;
};


/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
