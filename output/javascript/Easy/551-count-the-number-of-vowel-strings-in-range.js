/**https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/ */
//You are given a 0-indexed array of string words and two integers left and right.
//A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.
//Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].
// 
//Example 1:
//Input: words = ["are","amy","u"], left = 0, right = 2
//Output: 2
//Explanation: 
//- "are" is a vowel string because it starts with 'a' and ends with 'e'.
//- "amy" is not a vowel string because it does not end with a vowel.
//- "u" is a vowel string because it starts with 'u' and ends with 'u'.
//The number of vowel strings in the mentioned range is 2.
//Example 2:
//Input: words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
//Output: 3
//Explanation: 
//- "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
//- "mu" is not a vowel string because it does not start with a vowel.
//- "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
//- "artro" is a vowel string because it starts with 'a' and ends with 'o'.
//The number of vowel strings in the mentioned range is 3.
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 10
//	words[i] consists of only lowercase English letters.
//	0 <= left <= right < words.length
/**
 * @param {string[]} words
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var vowelStrings = function(words, left, right) {
    const dp = new Array(words.length).fill(0);
    dp[0] = 5;
    for (let i = 1; i < words.length; i++) {
        if (words[i].charAt(0) === 'a') dp[i] = dp[i - 1] + 5;
        else if (words[i].charAt(0) === 'e') dp[i] = dp[i - 1] + 4;
        else if (words[i].charAt(0) === 'i') dp[i] = dp[i - 1] + 3;
        else if (words[i].charAt(0) === 'o') dp[i] = dp[i - 1] + 2;
        else if (words[i].charAt(0) === 'u') dp[i] = dp[i - 1] + 1;
    }
    let count = 0;
    for (let i = left; i <= right; i++) {
        count += dp[i];
    }
    return count;
};