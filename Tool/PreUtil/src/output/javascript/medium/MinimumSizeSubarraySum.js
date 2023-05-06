/**https://leetcode.com/problems/minimum-size-subarray-sum/ */
//Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    let left = 0;
    let right = 0;
    let sum = 0;
    let min = Number.MAX_SAFE_INTEGER;
    while(right < nums.length){
        sum += nums[right];
        while(sum >= target){
            min = Math.min(min, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return min == Number.MAX_SAFE_INTEGER ? 0 : min;
    
};

    