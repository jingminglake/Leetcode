class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                if (res.empty() || res.back() < 0) {
                    res.push_back(asteroids[i]);
                } else {
                    if (res.back() < abs(asteroids[i])) {
                        res.pop_back();
                        i--; // reconsider because i still exist
                    } else if(res.back() == abs(asteroids[i])) {
                        res.pop_back();
                    }
                }
            } else {
                res.push_back(asteroids[i]);
            }
        }
        return res;
    }
};
