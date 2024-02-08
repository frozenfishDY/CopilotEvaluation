/**https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/ */
//Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
//Note that the subarray needs to be non-empty after deleting one element.
// 
//Example 1:
//Input: arr = [1,-2,0,3]
//Output: 4
//Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
//Example 2:
//Input: arr = [1,-2,-2,3]
//Output: 3
//Explanation: We just choose [3] and it's the maximum sum.
//Example 3:
//Input: arr = [-1,-1,-1,-1]
//Output: -1
//Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
// 
//Constraints:
//	1 <= arr.length <= 105
//	-104 <= arr[i] <= 104
/**
 * @param {number[]} arr
 * @return {number}
 */
var maximumSum = function(arr) {
    var len = arr.length;
	var dp0 = Array(len).fill(0);
	var dp1 = Array(len).fill(0);
	dp0[0] = arr[0];
	dp1[0] = -Infinity;
	var ans = dp0[0];
	for (var i = 1; i < len; i++) {
		dp0[i] = Math.max(arr[i], dp0[i - 1] + arr[i]);
		dp1[i] = Math.max(dp0[i - 1], dp1[i - 1] + arr[i]);
		ans = Math.max(ans, dp0[i], dp1[i]);
	}
	return ans;
};