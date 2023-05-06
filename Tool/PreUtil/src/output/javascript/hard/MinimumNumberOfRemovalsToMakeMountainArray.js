/**https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/ */
//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array nums, return the minimum number of elements to remove to make nums a mountain array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumMountainRemovals = function(nums) {
    let n = nums.length;
    let dp1 = new Array(n).fill(1);
    let dp2 = new Array(n).fill(1);
    for(let i = 1; i < n; i++){
        for(let j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp1[i] = Math.max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for(let i = n - 2; i >= 0; i--){
        for(let j = n - 1; j > i; j--){
            if(nums[i] > nums[j]){
                dp2[i] = Math.max(dp2[i], dp2[j] + 1);
            }
        }
    }
    let res = 0;
    for(let i = 0; i < n; i++){
        if(dp1[i] > 1 && dp2[i] > 1){
            res = Math.max(res, dp1[i] + dp2[i] - 1);
        }
    }
    return n - res;
    
};

    