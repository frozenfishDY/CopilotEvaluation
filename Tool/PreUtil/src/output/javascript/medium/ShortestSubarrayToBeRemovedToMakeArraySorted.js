/**https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/ */
//Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
//Return the length of the shortest subarray to remove.
//A subarray is a contiguous subsequence of the array.


/**
 * @param {number[]} arr
 * @return {number}
 */
var findLengthOfShortestSubarray = function(arr) {
    let left = 0;
    let right = arr.length - 1;
    while (left + 1 < arr.length && arr[left] <= arr[left + 1]) {
        left++;
    }
    if (left === arr.length - 1) {
        return 0;
    }
    while (right - 1 >= 0 && arr[right] >= arr[right - 1]) {
        right--;
    }
    let result = Math.min(arr.length - left - 1, right);
    let i = 0;
    let j = right;
    while (i <= left && j < arr.length) {
        if (arr[i] <= arr[j]) {
            result = Math.min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }
    return result;
    
    
};

    