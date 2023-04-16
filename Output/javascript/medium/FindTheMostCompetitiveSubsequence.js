/**https://leetcode.com/problems/find-the-most-competitive-subsequence/ */
//Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
//An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
//We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var mostCompetitive = function(nums, k) {
    let stack = [];
    for (let i = 0; i < nums.length; i++) {
        while (stack.length > 0 && nums[i] < stack[stack.length - 1] && stack.length + nums.length - i > k) {
            stack.pop();
        }
        if (stack.length < k) {
            stack.push(nums[i]);
        }
    }
    return stack;
    
};

    