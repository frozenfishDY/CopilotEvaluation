/**https://leetcode.com/problems/number-of-ways-to-split-array/ */
//You are given a 0-indexed integer array nums of length n.
//nums contains a valid split at index i if the following are true:
//The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
//There is at least one element to the right of i. That is, 0 <= i < n - 1.
//Return the number of valid splits in nums.


/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function(nums) {
    let n = nums.length;
    let sum = 0;
    let left = 0;
    let right = 0;
    let count = 0;
    let mod = 1000000007;
    let prefix = new Array(n);
    for (let i = 0; i < n; i++) {
        sum += nums[i];
        prefix[i] = sum;
    }
    for (let i = 0; i < n - 2; i++) {
        left = prefix[i];
        let max = Math.min(prefix[n - 1] - left, 2 * left);
        let min = Math.max(prefix[n - 2] - left, left);
        let start = i + 1;
        let end = n - 2;
        while (start <= end) {
            let mid = Math.floor((start + end) / 2);
            if (prefix[mid] >= min && prefix[mid] <= max) {
                count = (count + (mid - i)) % mod;
                break;
            } else if (prefix[mid] < min) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return count;
    
};

    