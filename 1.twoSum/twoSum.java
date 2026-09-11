import java.util.*;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        Map<Integer, Integer> m = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (m.containsKey(target - nums[i])) {
                res[1] = i;
                res[0] = m.get(target - nums[i]);
                return res;
            }
            m.put(nums[i], i);
        }
        return res;
    }
	public static void main(String[] args) {
		TwoSum s = new TwoSum();
		int[] nums = {2, 7, 11, 15};
		int target = 9;
		for (int n : s.twoSum(nums, target)) {
			System.out.print(n + " ");
		}
		System.out.println();
	}
}
