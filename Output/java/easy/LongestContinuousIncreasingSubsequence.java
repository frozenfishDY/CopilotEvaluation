/**https://leetcode.com/problems/longest-continuous-increasing-subsequence/ */
//Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.
//A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].


class LongestContinuousIncreasingSubsequence {
    public int findLengthOfLCIS(int[] nums) {
        int max = 0;
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            if(i == 0 || nums[i] > nums[i - 1]){
                count++;
            }else{
                count = 1;
            }
            max = Math.max(max, count);
        }
        return max;
        
    }
}

    