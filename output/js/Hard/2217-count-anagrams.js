/**https://leetcode.com/problems/count-anagrams/ */
//You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.
//A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
//For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
//Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 10^9 + 7.


/**
 * @param {string} s
 * @return {number}
 */
var countAnagrams = function(s) {
    let mod = 1000000007;
    let dp = new Array(s.length + 1).fill(0);
    dp[0] = 1;
    for(let i = 1; i <= s.length; i++){
        for(let j = 1; j <= i; j++){
            if(s[i - j] == ' '){
                continue;
            }
            let num = parseInt(s.substring(i - j, i));
            if(num <= 26){
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    return dp[s.length];
    
};

    