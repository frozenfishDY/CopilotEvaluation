/**https://leetcode.com/problems/percentage-of-letter-in-string/ */
//Given a string s and a character letter, return the percentage of characters in s that equal letter rounded down to the nearest whole percent.
// 
//Example 1:
//Input: s = "foobar", letter = "o"
//Output: 33
//Explanation:
//The percentage of characters in s that equal the letter 'o' is 2 / 6 * 100% = 33% when rounded down, so we return 33.
//Example 2:
//Input: s = "jjjj", letter = "k"
//Output: 0
//Explanation:
//The percentage of characters in s that equal the letter 'k' is 0%, so we return 0.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of lowercase English letters.
//	letter is a lowercase English letter.
/**
 * @param {string} s
 * @param {character} letter
 * @return {number}
 */
var percentageLetter = function(s, letter) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < s.length; i++) {
        let item = s[i];
        if (map.has(item)) {
            let count = map.get(item);
            map.set(item, count + 1);
        } else {
            map.set(item, 1);
        }
    }
    if (map.has(letter)) {
        let count = map.get(letter);
        result = (count / s.length * 100).toFixed(0);
    }
    return parseInt(result);
};