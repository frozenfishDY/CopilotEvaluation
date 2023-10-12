/**https://leetcode.com/problems/matrix-block-sum/ */
//Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//	i - k <= r <= i + k,
//	j - k <= c <= j + k, and
//	(r, c) is a valid position in the matrix.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//Output: [[12,21,16],[27,45,33],[24,39,28]]
//Example 2:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
//Output: [[45,45,45],[45,45,45],[45,45,45]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n, k <= 100
//	1 <= mat[i][j] <= 100
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[][]}
 */
var matrixBlockSum = function(mat, k) {
    var m = mat.length;
	var n = mat[0].length;
	var ans = Array(m).fill(0).map(() => Array(n).fill(0));
	var dp = Array(m + 1).fill(0).map(() => Array(n + 1).fill(0));
	for (var i = 1; i <= m; i++) {
		for (var j = 1; j <= n; j++) {
			dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	for (var i = 1; i <= m; i++) {
		for (var j = 1; j <= n; j++) {
			var r1 = Math.max(1, i - k);
			var c1 = Math.max(1, j - k);
			var r2 = Math.min(m, i + k);
			var c2 = Math.min(n, j + k);
			ans[i - 1][j - 1] = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
		}
	}
	return ans;
};