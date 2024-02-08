/**https://leetcode.com/problems/ugly-number-iii/ */
//An ugly number is a positive integer that is divisible by a, b, or c.
//Given four integers n, a, b, and c, return the nth ugly number.
// 
//Example 1:
//Input: n = 3, a = 2, b = 3, c = 5
//Output: 4
//Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
//Example 2:
//Input: n = 4, a = 2, b = 3, c = 4
//Output: 6
//Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
//Example 3:
//Input: n = 5, a = 2, b = 11, c = 13
//Output: 10
//Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
// 
//Constraints:
//	1 <= n, a, b, c <= 109
//	1 <= a * b * c <= 1018
//	It is guaranteed that the result will be in range [1, 2 * 109].
/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var nthUglyNumber = function(n, a, b, c) {
    var left = 1;
	var right = 2000000000;
	var ans = 0;
	while (left <= right) {
		var mid = left + Math.floor((right - left) / 2);
		var count = Math.floor(mid / a) + Math.floor(mid / b) + Math.floor(mid / c) - Math.floor(mid / lcm(a, b)) - Math.floor(mid / lcm(a, c)) - Math.floor(mid / lcm(b, c)) + Math.floor(mid / lcm(a, lcm(b, c)));
		if (count >= n) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return ans;
};
var gcd = function(a, b) {
	return b == 0 ? a : gcd(b, a % b);
}
var lcm = function(a, b) {
	return a * b / gcd(a, b);
}
