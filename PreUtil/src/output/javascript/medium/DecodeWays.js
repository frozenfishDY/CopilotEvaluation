/**https://leetcode.com/problems/decode-ways/ */
//A message containing letters from A-Z can be encoded into numbers using the following mapping:
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
//"AAJF" with the grouping (1 1 10 6)
//"KJF" with the grouping (11 10 6)
//Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
//Given a string s containing only digits, return the number of ways to decode it.
//The test cases are generated so that the answer fits in a 32-bit integer.


/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    let n = s.length;
    if(n == 0){
        return 0;
    }
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    dp[1] = s[0] == "0" ? 0 : 1;
    for(let i = 2; i <= n; i++){
        let oneDigit = parseInt(s.substring(i - 1, i));
        let twoDigit = parseInt(s.substring(i - 2, i));
        if(oneDigit >= 1){
            dp[i] += dp[i - 1];
        }
        if(twoDigit >= 10 && twoDigit <= 26){
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
    
};

    