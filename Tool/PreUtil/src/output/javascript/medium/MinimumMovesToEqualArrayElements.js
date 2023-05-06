/**https://leetcode.com/problems/minimum-moves-to-equal-array-elements/ */
//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment n - 1 elements of the array by 1.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    let n = nums.length;
    let min = nums[0];
    let sum = 0;
    for(let i = 0; i < n; i++){
        min = Math.min(min, nums[i]);
        sum += nums[i];
    }
    return sum - min * n;
    
};

    