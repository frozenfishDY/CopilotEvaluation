/**https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string s, return the number of unique non-empty substrings of s are present in base.


/**
 * @param {string} s
 * @return {number}
 */
var findSubstringInWraproundString = function(s) {
    let n = s.length;
    let dp = new Array(26).fill(0);
    let result = 0;
    let count = 0;
    for(let i = 0; i < n; i++){
        if(i > 0 && (s.charCodeAt(i) - s.charCodeAt(i - 1) == 1 || s.charCodeAt(i - 1) - s.charCodeAt(i) == 25)){
            count++;
        }else{
            count = 1;
        }
        let index = s.charCodeAt(i) - 'a'.charCodeAt(0);
        dp[index] = Math.max(dp[index], count);
    }
    for(let i = 0; i < 26; i++){
        result += dp[i];
    }
    return result;
    
};

    