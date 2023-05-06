/**https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/ */
//Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
//The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
//A subarray is a contiguous part of an array.


/**
 * @param {number[]} nums
 * @param {number} firstLen
 * @param {number} secondLen
 * @return {number}
 */
var maxSumTwoNoOverlap = function(nums, firstLen, secondLen) {
    let n = nums.length;
    let first = new Array(n);
    let second = new Array(n);
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += nums[i];
        if(i >= firstLen){
            sum -= nums[i - firstLen];
        }
        first[i] = sum;
    }
    sum = 0;
    for(let i = 0; i < n; i++){
        sum += nums[i];
        if(i >= secondLen){
            sum -= nums[i - secondLen];
        }
        second[i] = sum;
    }
    let result = 0;
    for(let i = firstLen - 1; i < n; i++){
        if(i - firstLen >= 0){
            result = Math.max(result, first[i] + second[i - firstLen]);
        }
        if(i + secondLen < n){
            result = Math.max(result, first[i] + second[i + secondLen]);
        }
    }
    return result;
    
};

    