/**https://leetcode.com/problems/minimum-additions-to-make-valid-string/ */
//Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.
//A string is called valid if it can be formed by concatenating the string "abc" several times.
// 
//Example 1:
//Input: word = "b"
//Output: 2
//Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "a" to obtain the valid string "abc".
//Example 2:
//Input: word = "aaa"
//Output: 6
//Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
//Example 3:
//Input: word = "abc"
//Output: 0
//Explanation: word is already valid. No modifications are needed. 
// 
//Constraints:
//	1 <= word.length <= 50
//	word consists of letters "a", "b" and "c" only. 
/**
 * @param {string} word
 * @return {number}
 */
var addMinimum = function(word) {
    let count = 0;
    let n = word.length;
    let a = 0, b = 0, c = 0;
    for (let i = 0; i < n; i++) {
        if (word[i] === 'a') {
            if (b > 0 || c > 0) {
                count++;
                b = 0;
                c = 0;
            }
            a++;
        } else if (word[i] === 'b') {
            if (a > 0) {
                a--;
                b++;
            } else if (c > 0) {
                count++;
                c = 0;
                b++;
            } else {
                count += 2;
                b++;
            }
        } else {
            if (a > 0) {
                a--;
                c++;
            } else if (b > 0) {
                b--;
                c++;
            } else {
                count += 2;
                c++;
            }
        }
    }
    if (b > 0 || c > 0) {
        count += 2;
    }
    return count;
};