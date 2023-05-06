/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//s only contains the letters 'a', 'b', and 'c'.
//s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//s contains at most a occurrences of the letter 'a'.
//s contains at most b occurrences of the letter 'b'.
//s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.


/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c) {
    let result = '';
    let map = {};
    map['a'] = a;
    map['b'] = b;
    map['c'] = c;
    let prev = '';
    while (true) {
        let max = 0;
        let maxKey = '';
        for (let key in map) {
            if (map[key] > max && key !== prev) {
                max = map[key];
                maxKey = key;
            }
        }
        if (max === 0) {
            break;
        }
        if (max >= 2) {
            result += maxKey + maxKey;
            map[maxKey] -= 2;
        } else {
            result += maxKey;
            map[maxKey]--;
        }
        prev = maxKey;
    }
    return result;
    
};

    