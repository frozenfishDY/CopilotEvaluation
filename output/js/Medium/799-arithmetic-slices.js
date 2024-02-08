/**https://leetcode.com/problems/arithmetic-slices/ */
//An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
//Given an integer array nums, return the number of arithmetic subarrays of nums.
//A subarray is a contiguous subsequence of the array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
    let n = nums.length;
    let dp = new Array(n).fill(0);
    let result = 0;
    for(let i = 2; i < n; i++){
        if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
            dp[i] = dp[i - 1] + 1;
        }
        result += dp[i];
    }
    return result;
    
};

    