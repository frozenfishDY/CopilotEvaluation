/**https://leetcode.com/problems/frog-jump-ii/ */
//You are given a 0-indexed integer array stones sorted in strictly increasing order representing the positions of stones in a river.
//A frog, initially on the first stone, wants to travel to the last stone and then return to the first stone. However, it can jump to any stone at most once.
//The length of a jump is the absolute difference between the position of the stone the frog is currently on and the position of the stone to which the frog jumps.
//More formally, if the frog is at stones[i] and is jumping to stones[j], the length of the jump is |stones[i] - stones[j]|.
//The cost of a path is the maximum length of a jump among all jumps in the path.
//Return the minimum cost of a path for the frog.


/**
 * @param {number[]} stones
 * @return {number}
 */
var maxJump = function(stones) {
    let n = stones.length;
    let dp = new Array(n).fill(0);
    let result = 0;
    for(let i = 1; i < n; i++){
        for(let j = 0; j < i; j++){
            if(stones[i] - stones[j] <= i - j){
                dp[i] = Math.max(dp[i], dp[j] + 1);
                result = Math.max(result, dp[i]);
            }
        }
    }
    return result;
    
    
};

    