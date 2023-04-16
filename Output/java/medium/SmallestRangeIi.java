/**https://leetcode.com/problems/smallest-range-ii/ */
//You are given an integer array nums and an integer k.
//For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
//The score of nums is the difference between the maximum and minimum elements in nums.
//Return the minimum score of nums after changing the values at each index.


class SmallestRangeIi {
    public int smallestRangeII(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int res = nums[n - 1] - nums[0];
        for(int i = 0; i < n - 1; i++){
            int max = Math.max(nums[i] + k, nums[n - 1] - k);
            int min = Math.min(nums[i + 1] - k, nums[0] + k);
            res = Math.min(res, max - min);
        }
        return res;
        
        
    }
}

    