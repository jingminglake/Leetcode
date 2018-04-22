class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty())
            vecs.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty())
            vecs.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        int res = -1;
        if (!hasNext())
            return res;
        pair<vector<int>::iterator, vector<int>::iterator> p = vecs.front();
        vecs.pop();
        if (p.first + 1 != p.second) {
            vecs.push(make_pair(p.first + 1, p.second));
        }
        res = *(p.first);
        return res;
    }

    bool hasNext() {
        return !vecs.empty();
    }
    queue<pair<vector<int>::iterator, vector<int>::iterator> > vecs;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
