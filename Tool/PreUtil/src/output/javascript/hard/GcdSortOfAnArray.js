/**https://leetcode.com/problems/gcd-sort-of-an-array/ */
//You are given an integer array nums, and you can perform the following operation any number of times on nums:
//Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].
//Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.


/**
 * @param {number[]} nums
 * @return {boolean}
 */
var gcdSort = function(nums) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums.length; j++) {
            let xor = nums[i] ^ nums[j];
            if (xor >= low && xor <= high) {
                result++;
            }
        }
    }
    return result;
    
    
};

    