/**https://leetcode.com/problems/super-washing-machines/ */
//You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.
//For each move, you could choose any m (1 <= m <= n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time.
//Given an integer array machines representing the number of dresses in each washing machine from left to right on the line, return the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.


/**
 * @param {number[]} machines
 * @return {number}
 */
var findMinMoves = function(machines) {
    let n = machines.length;
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += machines[i];
    }
    if(sum % n != 0){
        return -1;
    }
    let avg = sum / n;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(machines[i - 1] > machines[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = 0;
    for(let i = 1; i <= n; i++){
        ans += dp[n][i] * Math.abs(avg - machines[i - 1]);
    }
    return ans;
    
};

    