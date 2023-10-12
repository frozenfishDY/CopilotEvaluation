/**https://leetcode.com/problems/k-concatenation-maximum-sum/ */
//Given an integer array arr and an integer k, modify the array by repeating it k times.
//For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
//Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
//As the answer can be very large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,2], k = 3
//Output: 9
//Example 2:
//Input: arr = [1,-2,1], k = 5
//Output: 2
//Example 3:
//Input: arr = [-1,-2], k = 7
//Output: 0
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= k <= 105
//	-104 <= arr[i] <= 104
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var kConcatenationMaxSum = function(arr, k) {
    var mod = 1000000007;
	var sum = 0;
	for (var i = 0; i < arr.length; i++) {
		sum += arr[i];
	}
	var ans = 0;
	var dp = 0;
	for (var i = 0; i < arr.length; i++) {
		dp = Math.max(dp + arr[i], arr[i]);
		ans = Math.max(ans, dp);
	}
	var left = 0;
	dp = 0;
	for (var i = 0; i < arr.length; i++) {
		left += arr[i];
		dp = Math.max(dp + arr[i], arr[i]);
		ans = Math.max(ans, dp);
	}
	var right = 0;
	dp = 0;
	for (var i = arr.length - 1; i >= 0; i--) {
		right += arr[i];
		dp = Math.max(dp + arr[i], arr[i]);
		ans = Math.max(ans, dp);
	}
	if (k == 1) {
		return ans;
	}
	if (sum <= 0) {
		return Math.max(ans, left + right);
	}
	return Math.max(ans, left + right + (k - 2) * sum) % mod;

};