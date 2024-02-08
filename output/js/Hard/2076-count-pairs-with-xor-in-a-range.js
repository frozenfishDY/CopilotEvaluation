/**https://leetcode.com/problems/count-pairs-with-xor-in-a-range/ */
//Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.
//A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.


/**
 * @param {number[]} nums
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countPairs = function(nums, low, high) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            let xor = nums[i] ^ nums[j];
            if (xor >= low && xor <= high) {
                result++;
            }
        }
    }
    return result;
    
};

    