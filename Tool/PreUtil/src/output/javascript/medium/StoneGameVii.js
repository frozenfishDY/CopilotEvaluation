/**https://leetcode.com/problems/stone-game-vii/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.
//Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.
//Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.


/**
 * @param {number[]} stones
 * @return {number}
 */
var stoneGameVII = function(stones) {
    let n = stones.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    let sum = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + stones[i - 1];
    }
    for (let i = n - 2; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            dp[i][j] = Math.max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
    
};

    