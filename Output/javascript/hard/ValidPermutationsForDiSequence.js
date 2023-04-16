/**https://leetcode.com/problems/valid-permutations-for-di-sequence/ */
//You are given a string s of length n where s[i] is either:
//'D' means decreasing, or
//'I' means increasing.
//A permutation perm of n + 1 integers of all the integers in the range [0, n] is called a valid permutation if for all valid i:
//If s[i] == 'D', then perm[i] > perm[i + 1], and
//If s[i] == 'I', then perm[i] < perm[i + 1].
//Return the number of valid permutations perm. Since the answer may be large, return it modulo 109 + 7.


/**
 * @param {string} s
 * @return {number}
 */
var numPermsDISequence = function(s) {
    let dp = [];
    for(let i = 0; i <= s.length; i++){
        dp.push([]);
        for(let j = 0; j <= s.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= s.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= s.length; i++){
        for(let j = 1; j <= s.length; j++){
            if(s[i - 1] == 'D'){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = 0;
    for(let i = 0; i <= s.length; i++){
        ans += dp[s.length][i];
    }
    return ans;
    
};

    