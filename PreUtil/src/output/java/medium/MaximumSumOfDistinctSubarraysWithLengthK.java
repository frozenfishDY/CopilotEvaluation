/**https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/ */
//You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
//The length of the subarray is k, and
//All the elements of the subarray are distinct.
//Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
//A subarray is a contiguous non-empty sequence of elements within an array.


class MaximumSumOfDistinctSubarraysWithLengthK {
    public long maximumSubarraySum(int[] nums, int k) {
        long res = 0;
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                count++;
            }else{
                count = 1;
            }
            left[i] = count;
        }
        count = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1 || nums[i] != nums[i + 1]){
                count++;
            }else{
                count = 1;
            }
            right[i] = count;
        }
        for(int i = 0; i < n - 1; i++){
            if(nums[i] != nums[i + 1]){
                res = Math.max(res, nums[i] * left[i] + nums[i + 1] * right[i + 1]);
            }
            if(i > 0 && nums[i - 1] != nums[i + 1]){
                res = Math.max(res, nums[i - 1] * left[i - 1] + nums[i] * (left[i] - 1) + nums[i + 1] * right[i + 1]);
            }
        }
        return res;
        
    }
}
     
    