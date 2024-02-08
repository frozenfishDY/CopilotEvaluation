/**https://leetcode.com/problems/minimum-incompatibility/ */
//You are given an integer array nums and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.
//A subset's incompatibility is the difference between the maximum and minimum elements in that array.
//Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.
//A subset is a group integers that appear in the array with no particular order.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumIncompatibility = function(nums, k) {
    let n = nums.length;
    let m = 1 << n;
    let dp = new Array(m).fill(Infinity);
    dp[0] = 0;
    let freq = new Map();
    for(let num of nums){
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    let count = Array.from(freq.values());
    for(let i = 0; i < count.length; i++){
        let next = dp.slice();
        for(let j = 0; j < m; j++){
            if(dp[j] != Infinity){
                let mask = j;
                let sum = 0;
                for(let k = 0; k < n; k++){
                    if((mask & (1 << k)) == 0 && count[k] <= count[i]){
                        mask |= 1 << k;
                        sum += count[k];
                    }
                }
                if(sum <= count[i]){
                    next[mask] = Math.min(next[mask], dp[j] + count[i] - sum);
                }
            }
        }
        dp = next;
    }
    return dp[m - 1] == Infinity ? -1 : dp[m - 1];
    
};

    