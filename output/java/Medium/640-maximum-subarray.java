/**https://leetcode.com/problems/maximum-subarray/ */
//Given an integer array nums, find the subarray with the largest sum, and return its sum.


class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
            max = Math.max(max, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return max;
        
        
    }
}

    