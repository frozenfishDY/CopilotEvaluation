/**https://leetcode.com/problems/longest-substring-without-repeating-characters/ */
//Given a string s, find the length of the longest substring without repeating characters.


/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let map = {};
    let max = 0;
    let start = 0;
    for(let i = 0; i < s.length; i++){
        let char = s[i];
        if(map[char] != undefined){
            start = Math.max(start, map[char] + 1);
        }
        map[char] = i;
        max = Math.max(max, i - start + 1);
    }
    return max;
};

    