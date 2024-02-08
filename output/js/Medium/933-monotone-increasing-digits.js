/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var monotoneIncreasingDigits = function(n) {
    const digits = n.toString().split('');
    let i = 1;
    while (i < digits.length && digits[i - 1] <= digits[i]) {
        i++;
    }
    if (i < digits.length) {
        while (i > 0 && digits[i - 1] > digits[i]) {
            digits[i - 1]--;
            i--;
        }
        for (let j = i + 1; j < digits.length; j++) {
            digits[j] = '9';
        }
    }
    return parseInt(digits.join(''));
};