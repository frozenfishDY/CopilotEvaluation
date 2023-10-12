/**https://leetcode.com/problems/vowels-of-all-substrings/ */
//Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.
//A substring is a contiguous (non-empty) sequence of characters within a string.
//Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.
// 
//Example 1:
//Input: word = "aba"
//Output: 6
//Explanation: 
//All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
//- "b" has 0 vowels in it
//- "a", "ab", "ba", and "a" have 1 vowel each
//- "aba" has 2 vowels in it
//Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
//Example 2:
//Input: word = "abc"
//Output: 3
//Explanation: 
//All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
//- "a", "ab", and "abc" have 1 vowel each
//- "b", "bc", and "c" have 0 vowels each
//Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.
//Example 3:
//Input: word = "ltcd"
//Output: 0
//Explanation: There are no vowels in any substring of "ltcd".
// 
//Constraints:
//	1 <= word.length <= 105
//	word consists of lowercase English letters.
/**
 * @param {string} word
 * @return {number}
 */
var countVowels = function(word) {
    let n = word.length;
    let res = 0;
    let count = new Array(5).fill(0);
    let vowels = new Map();
    vowels.set('a', 0);
    vowels.set('e', 1);
    vowels.set('i', 2);
    vowels.set('o', 3);
    vowels.set('u', 4);
    let bit = 0;
    let mask = 0;
    let one = 1;
    for (let i = 0; i < n; i++) {
        let ch = word[i];
        if (vowels.has(ch)) {
            bit ^= one << vowels.get(ch);
        }
        for (let j = 0; j < 5; j++) {
            if ((bit & (one << j)) > 0) {
                count[j]++;
            }
        }
        mask |= bit;
        for (let j = 0; j < 5; j++) {
            if ((mask & (one << j)) > 0) {
                res += count[j];
            }
        }
    }
    return res;
};