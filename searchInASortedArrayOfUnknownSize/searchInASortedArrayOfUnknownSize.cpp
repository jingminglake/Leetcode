// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 10000;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int val = reader.get(mid);
            if (val > target) {
                right = mid;
            } else if (val < target) {
                left = mid;
            } else {
                return mid;
            }
        }
        if (reader.get(left) == target) return left;
        if (reader.get(right) == target) return right;
        return -1;
    }
};
