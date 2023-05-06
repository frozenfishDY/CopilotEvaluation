/**https://leetcode.com/problems/stone-game-viii/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//There are n stones arranged in a row. On each player's turn, while the number of stones is more than one, they will do the following:
//Choose an integer x > 1, and remove the leftmost x stones from the row.
//Add the sum of the removed stones' values to the player's score.
//Place a new stone, whose value is equal to that sum, on the left side of the row.
//The game stops when only one stone is left in the row.
//The score difference between Alice and Bob is (Alice's score - Bob's score). Alice's goal is to maximize the score difference, and Bob's goal is the minimize the score difference.
//Given an integer array stones of length n where stones[i] represents the value of the ith stone from the left, return the score difference between Alice and Bob if they both play optimally.


/**
 * @param {number[]} stones
 * @return {number}
 */
var stoneGameVIII = function(stones) {
    let n = stones.length;
    let dp = new Array(n).fill(0);
    dp[n - 1] = stones[n - 1];
    for(let i = n - 2; i >= 0; i--){
        dp[i] = dp[i + 1] + stones[i];
    }
    let max = dp[0];
    for(let i = 1; i < n - 1; i++){
        max = Math.max(max, dp[i] - max);
    }
    return max;
    
};

    