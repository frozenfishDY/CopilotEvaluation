/**https://leetcode.com/problems/smallest-range-ii/ */
//You are given an integer array nums and an integer k.
//For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
//The score of nums is the difference between the maximum and minimum elements in nums.
//Return the minimum score of nums after changing the values at each index.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var smallestRangeII = function(nums, k) {
    let n = nums.length;
    let result = 0;
    nums.sort((a, b) => a - b);
    for(let i = 0; i < n - 1; i++){
        let a = nums[i];
        let b = nums[i + 1];
        let high = Math.max(nums[n - 1] - k, a + k);
        let low = Math.min(nums[0] + k, b - k);
        result = Math.min(result, high - low);
    }
    return result;
    
};

    