/**https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/ */
//Alice is a caretaker of n gardens and she wants to plant flowers to maximize the total beauty of all her gardens.
//You are given a 0-indexed integer array flowers of size n, where flowers[i] is the number of flowers already planted in the ith garden. Flowers that are already planted cannot be removed. You are then given another integer newFlowers, which is the maximum number of flowers that Alice can additionally plant. You are also given the integers target, full, and partial.
//A garden is considered complete if it has at least target flowers. The total beauty of the gardens is then determined as the sum of the following:
//The number of complete gardens multiplied by full.
//The minimum number of flowers in any of the incomplete gardens multiplied by partial. If there are no incomplete gardens, then this value will be 0.
//Return the maximum total beauty that Alice can obtain after planting at most newFlowers flowers.


/**
 * @param {number[]} flowers
 * @param {number} newFlowers
 * @param {number} target
 * @param {number} full
 * @param {number} partial
 * @return {number}
 */
var maximumBeauty = function(flowers, newFlowers, target, full, partial) {
    let n = flowers.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(newFlowers + 1).fill(0);
    }
    let sum = new Array(n + 1);
    sum[0] = 0;
    for(let i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + flowers[i - 1];
    }
    for(let i = 1; i <= n; i++){
        for(let j = 0; j <= newFlowers; j++){
            let min = Infinity;
            for(let k = 0; k <= j; k++){
                let complete = Math.floor((sum[i] + k) / target);
                let incomplete = (sum[i] + k) % target;
                min = Math.min(min, incomplete);
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - k] + complete * full + min * partial);
            }
        }
    }
    return dp[n][newFlowers];
    
};

    