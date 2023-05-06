/**https://leetcode.com/problems/matchsticks-to-square/ */
//You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//Return true if you can make this square and false otherwise.


/**
 * @param {number[]} matchsticks
 * @return {boolean}
 */
var makesquare = function(matchsticks) {
    let n = matchsticks.length;
    if(n < 4){
        return false;
    }
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += matchsticks[i];
    }
    if(sum % 4 != 0){
        return false;
    }
    let target = sum / 4;
    matchsticks.sort((a, b) => b - a);
    let sides = new Array(4).fill(0);
    return dfs(matchsticks, sides, 0, target);
    
    
};

    