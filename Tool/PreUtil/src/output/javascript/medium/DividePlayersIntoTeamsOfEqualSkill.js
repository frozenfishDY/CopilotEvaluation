/**https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/ */
//You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
//The chemistry of a team is equal to the product of the skills of the players on that team.
//Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.


/**
 * @param {number[]} skill
 * @return {number}
 */
var dividePlayers = function(skill) {
    let n = skill.length;
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += skill[i];
    }
    if(sum % (n / 2) != 0){
        return -1;
    }
    let target = sum / (n / 2);
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    for(let i = 0; i < n; i++){
        for(let j = n; j >= skill[i]; j--){
            dp[j] = Math.max(dp[j], dp[j - skill[i]]);
        }
    }
    if(dp[target] == 0){
        return -1;
    }
    let result = 0;
    for(let i = 0; i < n; i++){
        result += skill[i] * skill[n - i - 1];
    }
    return result;
    
};

    