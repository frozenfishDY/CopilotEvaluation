/**https://leetcode.com/problems/minimum-moves-to-make-array-complementary/ */
//You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.
//The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
//Return the minimum number of moves required to make nums complementary.


/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number}
 */
var minMoves = function(nums, limit) {
    let n = nums.length;
    let diff = new Array(2 * limit + 2).fill(0);
    for (let i = 0; i < n / 2; i++) {
        let a = nums[i];
        let b = nums[n - 1 - i];
        diff[2] += 2;
        diff[Math.min(a, b) + 1] -= 1;
        diff[a + b] -= 1;
        diff[a + b + 1] += 1;
        diff[Math.max(a, b) + limit + 1] += 1;
    }
    let res = n;
    let cur = 0;
    for (let i = 2; i <= 2 * limit; i++) {
        cur += diff[i];
        res = Math.min(res, cur);
    }
    return res;
    
};

    