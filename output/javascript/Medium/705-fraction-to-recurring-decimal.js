/**https://leetcode.com/problems/fraction-to-recurring-decimal/ */
//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//If multiple answers are possible, return any of them.
//It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
// 
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//Example 3:
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
// 
//Constraints:
//	-231 <= numerator, denominator <= 231 - 1
//	denominator != 0
/**
 * @param {number} numerator
 * @param {number} denominator
 * @return {string}
 */
var fractionToDecimal = function(numerator, denominator) {
    //console.log(numerator, denominator);
	let isNegative = false;
	if (numerator < 0 && denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	} else if (numerator < 0) {
		numerator = -numerator;
		isNegative = true;
	} else if (denominator < 0) {
		denominator = -denominator;
		isNegative = true;
	}
	let result = Math.floor(numerator / denominator);
	let remainder = numerator % denominator;
	if (remainder === 0) {
		return isNegative ? -result : result;
	}
	let map = new Map();
	let arr = [];
	let index = 0;
	while (remainder !== 0) {
		if (map.has(remainder)) {
			let startIndex = map.get(remainder);
			let nonRepeating = arr.slice(0, startIndex);
			let repeating = arr.slice(startIndex);
			if (nonRepeating.length === 0) {
				return `${result}.${repeating.join("")}`;
			}
			return `${result}.${nonRepeating.join("")}(${repeating.join("")})`;
		}
		map.set(remainder, index);
		remainder *= 10;
		let digit = Math.floor(remainder / denominator);
		arr.push(digit);
		remainder %= denominator;
		index++;
	}
	return `${result}.${arr.join("")}`;
};