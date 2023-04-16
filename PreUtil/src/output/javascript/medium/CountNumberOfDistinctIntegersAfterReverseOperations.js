/**https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/ */
//You are given an array nums consisting of positive integers.
//You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
//Return the number of distinct integers in the final array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var countDistinctIntegers = function(nums) {
    let n = nums.length;
    let set = new Set();
    for (let i = 0; i < n; i++) {
        let reverse = parseInt(nums[i].toString().split('').reverse().join(''));
        set.add(reverse);
    }
    return set.size;
    
};

    