/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.


/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let max = "";
    for(let i = 0; i < s.length; i++){
        let odd = expandAroundCenter(s, i, i);
        let even = expandAroundCenter(s, i, i + 1);
        let longest = odd.length > even.length ? odd : even;
        max = longest.length > max.length ? longest : max;
    }
    return max;
    
};

    