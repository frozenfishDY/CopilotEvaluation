/**https://leetcode.com/problems/partition-array-into-disjoint-intervals/ */
//Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:
//Every element in left is less than or equal to every element in right.
//left and right are non-empty.
//left has the smallest possible size.
//Return the length of left after such a partitioning.
//Test cases are generated such that partitioning exists.


/**
 * @param {number[]} nums
 * @return {number}
 */
var partitionDisjoint = function(nums) {
    let n = nums.length;
    let left = new Array(n).fill(0);
    let right = new Array(n).fill(0);
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    for(let i = 1; i < n; i++){
        left[i] = Math.max(left[i - 1], nums[i]);
    }
    for(let i = n - 2; i >= 0; i--){
        right[i] = Math.min(right[i + 1], nums[i]);
    }
    for(let i = 0; i < n - 1; i++){
        if(left[i] <= right[i + 1]){
            return i + 1;
        }
    }
    return 0;
    
};

    