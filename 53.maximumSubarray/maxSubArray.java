import java.util.*;

class MaxSubArray {
    public int maxSubArray(int[] nums) {
        if (nums.length == 0)
            return 0;
        int local = nums[0];
        int global = nums[0];
        for (int i = 1; i < nums.length; i++) {
            local = Math.max(local + nums[i], nums[i]);
            global = Math.max (local, global);
        }
        return global;
    }
	public static void main(String[] args) {
		MaxSubArray s = new MaxSubArray();
		int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
		System.out.println(s.maxSubArray(nums));
	}
}
