/**https://leetcode.com/problems/binary-subarrays-with-sum/ */
//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
//A subarray is a contiguous part of the array.


/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var numSubarraysWithSum = function(nums, goal) {
    let n = nums.length;
    let count = new Array(n + 1).fill(0);
    let sum = 0;
    let result = 0;
    for(let i = 0; i < n; i++){
        count[sum]++;
        sum += nums[i];
        result += count[sum - goal];
    }
    return result;
    
    
};

    