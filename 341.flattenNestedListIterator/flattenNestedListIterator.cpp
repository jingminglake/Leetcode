class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
    }

    int next() {
        int res = -1;
        if (hasNext()) {
            res = s.top().getInteger();
            s.pop();
            return res;
        }
        return res;
    }

    bool hasNext() {
        while (!s.empty()) {
            if (s.top().isInteger())
                return true;
            NestedInteger ni = s.top();
            s.pop();
            flattenList(ni.getList());
        }
        return false;
    }
    
    void flattenList(vector<NestedInteger>& list) {
        for (int i = list.size() - 1; i >= 0; i--)
            s.push(list[i]);
    }
    stack<NestedInteger> s;
};
