/**https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/ */
//You are given a 0-indexed binary string s which represents a sequence of train cars. s[i] = '0' denotes that the ith car does not contain illegal goods and s[i] = '1' denotes that the ith car does contain illegal goods.
//As the train conductor, you would like to get rid of all the cars containing illegal goods. You can do any of the following three operations any number of times:
//Remove a train car from the left end (i.e., remove s[0]) which takes 1 unit of time.
//Remove a train car from the right end (i.e., remove s[s.length - 1]) which takes 1 unit of time.
//Remove a train car from anywhere in the sequence which takes 2 units of time.
//Return the minimum time to remove all the cars containing illegal goods.
//Note that an empty sequence of cars is considered to have no cars containing illegal goods.


/**
 * @param {string} s
 * @return {number}
 */
var minimumTime = function(s) {
    let dp = new Array(s.length + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(s.length + 1).fill(0);
    }
    for(let i = 1; i <= s.length; i++){
        for(let j = 1; j <= s.length; j++){
            if(s[i - 1] === '1'){
                dp[i][j] = Math.min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2);
            } else {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[s.length][s.length];
    
};

    