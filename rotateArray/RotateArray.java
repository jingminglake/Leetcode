import java.util.*;
class RotateArray {
    public void rotate(int[] nums, int k) {
        if (nums.length == 0)
            return;
        k = k % nums.length;
        reverse(nums, 0, nums.length - k - 1);
        reverse(nums, nums.length - k, nums.length - 1);
        reverse(nums, 0, nums.length - 1);
    }
    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
	public static void main(String[] args) {
		RotateArray s = new RotateArray();
		int a[] = {1,2,3,4,5,6,7};
		int k = 3;
		s.rotate(a, k);
		for (int n : a)
			System.out.print(n + " ");
		System.out.println();
	}
}
