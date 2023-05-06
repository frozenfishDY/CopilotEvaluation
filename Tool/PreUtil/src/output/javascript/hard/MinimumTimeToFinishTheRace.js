/**https://leetcode.com/problems/minimum-time-to-finish-the-race/ */
//You are given a 0-indexed 2D integer array tires where tires[i] = [fi, ri] indicates that the ith tire can finish its xth successive lap in fi * ri(x-1) seconds.
//For example, if fi = 3 and ri = 2, then the tire would finish its 1st lap in 3 seconds, its 2nd lap in 3 * 2 = 6 seconds, its 3rd lap in 3 * 22 = 12 seconds, etc.
//You are also given an integer changeTime and an integer numLaps.
//The race consists of numLaps laps and you may start the race with any tire. You have an unlimited supply of each tire and after every lap, you may change to any given tire (including the current tire type) if you wait changeTime seconds.
//Return the minimum time to finish the race.


/**
 * @param {number[][]} tires
 * @param {number} changeTime
 * @param {number} numLaps
 * @return {number}
 */
var minimumFinishTime = function(tires, changeTime, numLaps) {
    let n = tires.length;
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(numLaps + 1).fill(0);
    }
    for(let i = 0; i < n; i++){
        for(let j = 1; j <= numLaps; j++){
            dp[i][j] = Infinity;
            for(let k = 0; k < n; k++){
                if(i == k){
                    dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + tires[i][0] * tires[i][1] * j);
                }else{
                    dp[i][j] = Math.min(dp[i][j], dp[k][j - 1] + changeTime + tires[i][0] * tires[i][1] * j);
                }
            }
        }
    }
    let ans = Infinity;
    for(let i = 0; i < n; i++){
        ans = Math.min(ans, dp[i][numLaps]);
    }
    return ans;
    
};

    