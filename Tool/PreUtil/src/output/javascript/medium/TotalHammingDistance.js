/**https://leetcode.com/problems/total-hamming-distance/ */
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.


/**
 * @param {number[]} nums
 * @return {number}
 */
var totalHammingDistance = function(nums) {
    let n = nums.length;
    let result = 0;
    for(let i = 0; i < 32; i++){
        let count = 0;
        for(let j = 0; j < n; j++){
            count += (nums[j] >> i) & 1;
        }
        result += count * (n - count);
    }
    return result;
    
};

    