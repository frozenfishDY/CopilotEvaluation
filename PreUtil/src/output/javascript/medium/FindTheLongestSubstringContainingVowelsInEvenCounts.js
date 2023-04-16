/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.


/**
 * @param {string} s
 * @return {number}
 */
var findTheLongestSubstring = function(s) {
    let result = 0;
    let left = 0;
    let right = 0;
    let map = new Map();
    map.set("a", 0);
    map.set("e", 0);
    map.set("i", 0);
    map.set("o", 0);
    map.set("u", 0);
    while(right < s.length){
        if(map.has(s[right])){
            map.set(s[right], map.get(s[right]) + 1);
        }
        while(isValid(map)){
            result = Math.max(result, right - left + 1);
            if(map.has(s[left])){
                map.set(s[left], map.get(s[left]) - 1);
            }
            left++;
        }
        right++;
    }
    return result;
    
    
    
};

    