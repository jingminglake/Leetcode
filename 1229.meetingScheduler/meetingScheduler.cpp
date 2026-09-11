class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int p1 = 0, p2 = 0;
        while (p1 < slots1.size() && p2 < slots2.size()) {
            int left = max (slots1[p1][0], slots2[p2][0]);
            int right = min (slots1[p1][1], slots2[p2][1]);
            if (right - left >= duration) {
                return {left, left + duration};
            } else if (slots1[p1][1] < slots2[p2][1]) {
                p1++;
            } else {
                p2++;
            }
        }
        return {};
    }
};
