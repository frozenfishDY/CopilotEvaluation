/**https://leetcode.com/problems/scramble-string/ */
//We can scramble a string s to get a string t using the following algorithm:
//If the length of the string is 1, stop.
//If the length of the string is > 1, do the following:
//Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
//Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
//Apply step 1 recursively on each of the two substrings x and y.
//Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.


/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    let m = s1.length;
    let n = s2.length;
    if(m !== n){
        return false;
    }
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= m; k++){
                dp[i][j].push(false);
            }
        }
    }
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            dp[i][j][1] = s1[i] === s2[j];
        }
    }
    for(let len = 2; len <= m; len++){
        for(let i = 0; i <= m - len; i++){
            for(let j = 0; j <= n - len; j++){
                for(let k = 1; k < len; k++){
                    if((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i][j + len - k][k] && dp[i + k][j][len - k])){
                        dp[i][j][len] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[0][0][m];
    
};

    