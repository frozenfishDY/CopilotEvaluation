/**https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/ */
//You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.
//Return the minimum number of moves required so that nums has k consecutive 1's.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minMoves = function(nums, k) {
    let n = nums.length;
    let ones = [];
    for(let i = 0; i < n; i++){
        if(nums[i] == 1){
            ones.push(i);
        }
    }
    let m = ones.length;
    let prefix = new Array(m + 1).fill(0);
    for(let i = 1; i <= m; i++){
        prefix[i] = prefix[i - 1] + ones[i - 1];
    }
    let dp = new Array(m + 1).fill(0);
    for(let i = 1; i <= m; i++){
        dp[i] = dp[i - 1] + (ones[i - 1] - ones[(i - 1) - (k - 1) / 2]) * (k % 2 == 0 ? 1 : 2);
    }
    let res = Infinity;
    for(let i = k - 1; i < m; i++){
        let left = i - (k - 1) / 2;
        let right = i + (k - 1) / 2;
        let sum = prefix[right + 1] - prefix[left];
        let mid = ones[Math.floor((left + right) / 2)];
        res = Math.min(res, dp[i + 1] - dp[left] - (sum - mid * (right - left + 1)));
    }
    return res;
    
};

    