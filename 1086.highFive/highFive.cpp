class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int> > res;
        map<int, priority_queue<int, vector<int>, greater<int>>> treeM;
        for (vector<int>& item : items) {
            priority_queue<int, vector<int>, greater<int>>& pq = treeM[item[0]];
            pq.push(item[1]);
            if (pq.size() > 5) pq.pop();
        }
        for (auto& p : treeM) {
            priority_queue<int, vector<int>, greater<int>>& pq = p.second;
            int sum = 0;
            int size = pq.size();
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            res.push_back({p.first, sum / size});
        }
        return res;
    }
};
