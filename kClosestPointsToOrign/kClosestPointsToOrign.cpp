class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.size() <= K) return points;
        int kth_index = findKthIndex(points, K, 0, points.size() - 1);
        return vector<vector<int>> (points.begin(), points.begin() + kth_index);
    }
    
    int findKthIndex(vector<vector<int>>& points, int k, int left, int right) {
        if (left >= right) return left;
        int pos = left + rand() % (right - left);
        swap(points[left], points[pos]);
        vector<int>& pivot = points[left];
        int last = left;
        for (int i = left + 1; i <= right; i++) {
            if (closer(points[i], pivot)) swap(points[++last], points[i]);
        }
        swap(points[left], points[last]);
        if (last == k) {
            return last;
        } else if (last < k) {
            return findKthIndex(points, k, last + 1, right);
        } else {
            return findKthIndex(points, k, left, last - 1);
        }
    }
    
    bool closer(const vector<int>& p1, const vector<int>& p2) {
        return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
    }
};
