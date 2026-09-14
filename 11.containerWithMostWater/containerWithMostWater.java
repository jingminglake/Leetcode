class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int res = 0;
        while (left < right) {
            int width = right - left;
            if (height[left] < height[right]) {
                res = Math.max(res, (height[left] * width));
                left++;
            } else {
                res = Math.max(res, (height[right] * width));
                right--;
            }
        }
        return res;
    }
}