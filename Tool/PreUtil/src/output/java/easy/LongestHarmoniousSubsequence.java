/**https://leetcode.com/problems/longest-harmonious-subsequence/ */
//We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
//Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
//A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.


class LongestHarmoniousSubsequence {
    public int findLHS(int[] nums) {
        int max = 0;
        for(int i = 0; i < nums.length; i++){
            int count = 0;
            for(int j = 0; j < nums.length; j++){
                if(nums[i] == nums[j] || nums[i] == nums[j] + 1){
                    count++;
                }
            }
            max = Math.max(max, count);
        }
        return max;
        
    }
}

    