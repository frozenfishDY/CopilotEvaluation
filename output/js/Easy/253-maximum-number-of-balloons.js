/**https://leetcode.com/problems/maximum-number-of-balloons/ */
//Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
//You can use each character in text at most once. Return the maximum number of instances that can be formed.
// 
//Example 1:
//Input: text = "nlaebolko"
//Output: 1
//Example 2:
//Input: text = "loonbalxballpoon"
//Output: 2
//Example 3:
//Input: text = "leetcode"
//Output: 0
// 
//Constraints:
//	1 <= text.length <= 104
//	text consists of lower case English letters only.
/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    let map = new Map();
    for (let c of text) {
        map.set(c, (map.get(c) || 0) + 1);
    }
    let res = Number.MAX_VALUE;
    for (let c of 'balloon') {
        if (!map.has(c)) {
            return 0;
        }
        if (c === 'l' || c === 'o') {
            res = Math.min(res, Math.floor(map.get(c) / 2));
        } else {
            res = Math.min(res, map.get(c));
        }
    }
    return res;
};