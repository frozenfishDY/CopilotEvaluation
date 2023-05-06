/**https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/ */
//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment or decrement an element of the array by 1.
//Test cases are designed so that the answer will fit in a 32-bit integer.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    let n = nums.length;
    nums.sort((a, b) => a - b);
    let median = nums[Math.floor(n / 2)];
    let result = 0;
    for(let i = 0; i < n; i++){
        result += Math.abs(nums[i] - median);
    }
    return result;
    
};

    