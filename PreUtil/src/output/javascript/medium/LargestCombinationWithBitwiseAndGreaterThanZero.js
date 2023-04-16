/**https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/ */
//The bitwise AND of an array nums is the bitwise AND of all integers in nums.
//For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
//Also, for nums = [7], the bitwise AND is 7.
//You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.
//Return the size of the largest combination of candidates with a bitwise AND greater than 0.


/**
 * @param {number[]} candidates
 * @return {number}
 */
var largestCombination = function(candidates) {
    let n = candidates.length;
    let max = 0;
    let map = {};
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let and = candidates[i] & candidates[j];
            if (and > 0) {
                map[and] = true;
                max = Math.max(max, and);
            }
        }
    }
    return max;
    
};

    