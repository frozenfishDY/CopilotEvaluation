/**https://leetcode.com/problems/find-xor-beauty-of-array/ */
//You are given a 0-indexed integer array nums.
//The effective value of three indices i, j, and k is defined as ((nums[i] | nums[j]) & nums[k]).
//The xor-beauty of the array is the XORing of the effective values of all the possible triplets of indices (i, j, k) where 0 <= i, j, k < n.
//Return the xor-beauty of nums.
//Note that:
//val1 | val2 is bitwise OR of val1 and val2.
//val1 & val2 is bitwise AND of val1 and val2.


/**
 * @param {number[]} nums
 * @return {number}
 */
var xorBeauty = function(nums) {
    let n = nums.length;
    let result = 0;
    for(let i = 0; i < n; i++){
        for(let j = i; j < n; j++){
            for(let k = j; k < n; k++){
                result ^= ((nums[i] | nums[j]) & nums[k]);
            }
        }
    }
    return result;
    
};

    