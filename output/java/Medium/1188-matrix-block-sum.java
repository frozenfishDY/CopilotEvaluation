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
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int[][] ans = new int[mat.length][mat[0].length];
        int[][] sum = new int[mat.length+1][mat[0].length+1];
        for(int i = 1; i <= mat.length; i++) {
            for(int j = 1; j <= mat[0].length; j++) {
                sum[i][j] = mat[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
        for(int i = 1; i <= mat.length; i++) {
            for(int j = 1; j <= mat[0].length; j++) {
                int r1 = Math.max(i-k-1, 0);
                int c1 = Math.max(j-k-1, 0);
                int r2 = Math.min(i+k, mat.length);
                int c2 = Math.min(j+k, mat[0].length);
                ans[i-1][j-1] = sum[r2][c2]-sum[r1][c2]-sum[r2][c1]+sum[r1][c1];
            }
        }
        return ans;
    }
}