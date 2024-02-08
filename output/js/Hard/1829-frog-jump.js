/**https://leetcode.com/problems/frog-jump/ */
//A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
//If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.


/**
 * @param {number[]} stones
 * @return {boolean}
 */
var canCross = function(stones) {
    let n = stones.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push(false);
        }
    }
    dp[0][0] = true;
    for(let i = 1; i < n; i++){
        if(stones[i] - stones[i - 1] > i){
            return false;
        }
    }
    for(let i = 1; i < n; i++){
        for(let j = i - 1; j >= 0; j--){
            let k = stones[i] - stones[j];
            if(k > j + 1){
                break;
            }
            dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
            if(i == n - 1 && dp[i][k]){
                return true;
            }
        }
    }
    return false;
    
};

    