/**https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/ */
//Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
//The test cases are generated so that the answer will fit in a 32-bit integer.


/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var numSubarrayBoundedMax = function(nums, left, right) {
    let n = nums.length;
    let dp = new Array(n + 1).fill(0);
    let result = 0;
    let prev = 0;
    for(let i = 0; i < n; i++){
        if(nums[i] >= left && nums[i] <= right){
            dp[i + 1] = i + 1 - prev;
        }
        else if(nums[i] < left){
            dp[i + 1] = dp[i];
        }
        else{
            prev = i + 1;
        }
        result += dp[i + 1];
    }
    return result;
    
};

    