/**https://leetcode.com/problems/longest-square-streak-in-an-array/ */
//You are given an integer array nums. A subsequence of nums is called a square streak if:
//The length of the subsequence is at least 2, and
//after sorting the subsequence, each element (except the first element) is the square of the previous number.
//Return the length of the longest square streak in nums, or return -1 if there is no square streak.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function(nums) {
    let n = nums.length;
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(n).fill(0);
    }
    let result = 0;
    let map = new Map();
    for(let i = 0; i < n; i++){
        map.set(nums[i], i);
    }
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            let k = map.get(nums[j] - nums[i]);
            if(k !== undefined && k < i){
                dp[i][j] = dp[k][i] + 1;
                result = Math.max(result, dp[i][j]);
            }
        }
    }
    return result === 0 ? -1 : result + 2;

    
};

    