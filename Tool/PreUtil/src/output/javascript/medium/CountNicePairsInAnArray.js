/**https://leetcode.com/problems/count-nice-pairs-in-an-array/ */
//You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:
//0 <= i < j < nums.length
//nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
//Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.


/**
 * @param {number[]} nums
 * @return {number}
 */
var countNicePairs = function(nums) {
    let map = new Map();
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        let rev = parseInt(nums[i].toString().split("").reverse().join(""));
        let diff = nums[i] - rev;
        if (map.has(diff)) {
            count = (count + map.get(diff)) % 1000000007;
            map.set(diff, map.get(diff) + 1);
        } else {
            map.set(diff, 1);
        }
    }
    return count;
    
};

    