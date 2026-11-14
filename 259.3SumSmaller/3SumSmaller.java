class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int res = 0;
        int len = nums.length;
        if (len < 3) return 0;
        for (int i = 0; i < len - 2; i++) {
            int subT = target - nums[i];

            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                int sumTwo = nums[left] + nums[right];
                if (sumTwo < subT) {
                    res += right - left; // nums[left] 和 (left, right] 里的任何一个配对, 都<sumT
                    left++;
                } else {
                    right--; // nums[right] 和 [left, right) 里的任何一个配对, 都是 >= sumT
                }
            }
        }
        return res;
    }
}

/*

[-2, 0, 1, 3], target = 2
n1 + n2 + n3 <= target ==> n2 + n3 <= target - n1;

len = 4

i = 0
subTarget = 2 - (-2) = 4
left = 1, right = 3

   0   1   3
0      1   3
1          4
3


left = 1, right = 3, sumTwo = nums[1] + nums[3] = 0 + 3; 3 < 4; res += 3 - 1 = 2; left = 1 + 1
left = 2, right = 3, sumTwo = nums[2] + nums[3] = 1 + 3; 4 == 4; right = 3 - 1 = 2

left: 2 < right: 2? false

i = 1 < len - 2 = 2 

subTarget = 2 - 0 = 2

left = i + 1 = 2, right = len - 1 = 3;

2 < 3 ?

left=2, right=3,  sumTwo = nums[2] + nums[3] = 4; 4 < 2 ? right = 3-1 =2

left: 2 < right: 2? false

i = 2 < len - 2 ? false

return 2

*/