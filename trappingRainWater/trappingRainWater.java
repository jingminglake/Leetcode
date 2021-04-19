class Solution {
    public int trap(int[] height) {
        int res = 0;
        int left = 0, right = height.length - 1;
        int leftM = 0, rightM = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftM) {
                    leftM = height[left];
                } else {
                    res += leftM - height[left];
                }
                left++;
            } else {
                if (height[right] > rightM) {
                    rightM = height[right];
                } else {
                    res += rightM - height[right];
                }
                right--;
            }
        }
        return res;
    }
}
