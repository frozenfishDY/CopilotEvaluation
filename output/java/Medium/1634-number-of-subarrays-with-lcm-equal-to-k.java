/**https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.
// 
//Example 1:
//Input: nums = [3,6,2,7,1], k = 6
//Output: 4
//Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//Example 2:
//Input: nums = [3], k = 2
//Output: 0
//Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.


class NumberOfSubarraysWithLcmEqualToK {
    public int subarrayLCM(int[] nums, int k) {
        int count = 0;
        int[] dp = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            if(nums[i] % k == 0){
                dp[i] = 1;
            }
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] % k == 0){
                    dp[j] = 0;
                }
                if(nums[j] % k == 0 && nums[i] % k == 0){
                    dp[j] = dp[j] + 1;
                }
                if(nums[j] % k == 0 && nums[i] % k != 0){
                    dp[j] = dp[j] + 1;
                }
                if(nums[j] % k != 0 && nums[i] % k == 0){
                    dp[j] = dp[j] + 1;
                }
                if(nums[j] % k != 0 && nums[i] % k != 0){
                    dp[j] = dp[j] + 1;
                }
            }
            for(int j = 0; j < dp.length; j++){
                count += dp[j];
            }
        }
        return count;
        
    }
}

    