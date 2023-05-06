/**https://leetcode.com/problems/construct-k-palindrome-strings/ */
//Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.


/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    if (k > s.length) {
        return false;
    }
    let map = {};
    for (let i = 0; i < s.length; i++) {
        if (map[s[i]]) {
            map[s[i]]++;
        } else {
            map[s[i]] = 1;
        }
    }
    let odd = 0;
    for (let key in map) {
        if (map[key] % 2 !== 0) {
            odd++;
        }
    }
    return odd <= k;
    
};

    