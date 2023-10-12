/**https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/ */
//You are given an integer num. You know that Danny Mittal will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
//Return the difference between the maximum and minimum values Danny can make by remapping exactly one digit in num.
//Notes:
//	When Danny remaps a digit d1 to another digit d2, Danny replaces all occurrences of d1 in num with d2.
//	Danny can remap a digit to itself, in which case num does not change.
//	Danny can remap different digits for obtaining minimum and maximum values respectively.
//	The resulting number after remapping can contain leading zeroes.
//	We mentioned "Danny Mittal" to congratulate him on being in the top 10 in Weekly Contest 326.
// 
//Example 1:
//Input: num = 11891
//Output: 99009
//Explanation: 
//To achieve the maximum value, Danny can remap the digit 1 to the digit 9 to yield 99899.
//To achieve the minimum value, Danny can remap the digit 1 to the digit 0, yielding 890.
//The difference between these two numbers is 99009.
//Example 2:
//Input: num = 90
//Output: 99
//Explanation:
//The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
//Thus, we return 99.
// 
//Constraints:
//	1 <= num <= 108
/**
 * @param {number} num
 * @return {number}
 */
var minMaxDifference = function(num) {
    const str = num.toString();
    const set = new Set();
    for (let i = 0; i < str.length; i++) {
        set.add(str.charAt(i));
    }
    const arr = [...set];
    const map = new Map();
    for (let i = 0; i < arr.length; i++) {
        map.set(arr[i], i);
    }
    let min = Number.MAX_SAFE_INTEGER;
    let max = Number.MIN_SAFE_INTEGER;
    for (let i = 0; i < str.length; i++) {
        const n = map.get(str.charAt(i));
        if (i === 0 && n === 0) continue;
        min = Math.min(min, parseInt(str.substring(0, i) + arr[0] + str.substring(i + 1)));
        max = Math.max(max, parseInt(str.substring(0, i) + arr[arr.length - 1] + str.substring(i + 1)));
    }
    return max - min;
};