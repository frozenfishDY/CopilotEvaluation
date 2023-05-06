/**https://leetcode.com/problems/longest-mountain-in-array/ */
//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.


/**
 * @param {number[]} arr
 * @return {number}
 */
var longestMountain = function(arr) {
    let n = arr.length;
    let left = new Array(n).fill(0);
    let right = new Array(n).fill(0);
    for(let i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]){
            left[i] = left[i - 1] + 1;
        }
    }
    for(let i = n - 2; i >= 0; i--){
        if(arr[i] > arr[i + 1]){
            right[i] = right[i + 1] + 1;
        }
    }
    let result = 0;
    for(let i = 0; i < n; i++){
        if(left[i] > 0 && right[i] > 0){
            result = Math.max(result, left[i] + right[i] + 1);
        }
    }
    return result;
    
};

    