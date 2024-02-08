/**https://leetcode.com/problems/minimum-operations-to-halve-array-sum/ */
//You are given an array nums of positive integers. In one operation, you can choose any number from nums and reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)
//Return the minimum number of operations to reduce the sum of nums by at least half.


/**
 * @param {number[]} nums
 * @return {number}
 */
var halveArray = function(nums) {
    let n = nums.length;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += nums[i];
    }
    let target = Math.ceil(sum / 2);
    let left = 0;
    let right = 0;
    let curr = 0;
    let result = n;
    while (right < n) {
        curr += nums[right];
        while (curr >= target) {
            result = Math.min(result, right - left + 1);
            curr -= nums[left];
            left++;
        }
        right++;
    }
    return n - result;
    
};

    