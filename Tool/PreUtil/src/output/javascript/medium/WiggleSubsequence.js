/**https://leetcode.com/problems/wiggle-subsequence/ */
//A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
//For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
//In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
//A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
//Given an integer array nums, return the length of the longest wiggle subsequence of nums.


/**
 * @param {number[]} nums
 * @return {number}
 */
var wiggleMaxLength = function(nums) {
    let n = nums.length;
    let up = new Array(n).fill(1);
    let down = new Array(n).fill(1);
    let result = 1;
    for(let i = 1; i < n; i++){
        for(let j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                up[i] = Math.max(up[i], down[j] + 1);
            }else if(nums[i] < nums[j]){
                down[i] = Math.max(down[i], up[j] + 1);
            }
        }
        result = Math.max(result, up[i], down[i]);
    }
    return result;
    
};

    