class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int len = nums.length;
        int[] res = new int[len];
        int indexes[] = new int[len];
        for (int i = 0; i < len; i++) indexes[i] = i;
        mergeSortWithCount(nums, indexes, res, 0, len - 1);
        List<Integer> resList = new ArrayList<>();
        for (int n : res) resList.add(n);
        return resList;
    }
    
    private void mergeSortWithCount(int[] nums, int[] indexes, int[] res, int start, int end) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeSortWithCount(nums, indexes, res, start, mid);
        mergeSortWithCount(nums, indexes, res, mid + 1, end);
        mergeAndCount(nums, indexes, res, start, mid, end);
    }
    
    private void mergeAndCount(int[] nums, int[] indexes, int[] res, int start, int mid, int end) {
        int[] helper = new int[end - start + 1];
        int left = start;
        int right = mid + 1;
        int index = 0;
        while (left <= mid && right <= end) {
            if (nums[indexes[left]] <= nums[indexes[right]]) {
                res[indexes[left]] += right - mid - 1;
                helper[index++] = indexes[left++];
            } else {
                helper[index++] = indexes[right++];
            }
        }
        while (left <= mid) {
            res[indexes[left]] += end - mid;
            helper[index++] = indexes[left++];
        }
        while (right <= end) {
            helper[index++] = indexes[right++];
        }
        for (int i = 0; i < helper.length; i++) {
            indexes[i + start] = helper[i];
        }
    }
}
