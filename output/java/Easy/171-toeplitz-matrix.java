/**https://leetcode.com/problems/toeplitz-matrix/ */
//Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
//A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
// 
//Example 1:
//Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
//Output: true
//Explanation:
//In the above grid, the diagonals are:
//"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
//In each diagonal all elements are the same, so the answer is True.
//Example 2:
//Input: matrix = [[1,2],[2,2]]
//Output: false
//Explanation:
//The diagonal "[1, 2]" has different elements.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 20
//	0 <= matrix[i][j] <= 99
// 
//Follow up:
//	What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
//	What if the matrix is so large that you can only load up a partial row into the memory at once?
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] arr = new int[m + n - 1];
        for (int i = 0; i < m + n - 1; ++i) {
            arr[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < m; ++i) {
            int[] temp = new int[n + 1];
            temp[0] = Integer.MAX_VALUE;
            for (int j = 0; j < n; ++j) {
                temp[j + 1] = matrix[i][j];
            }
            for (int j = 0; j < n; ++j) {
                arr[i - j + n - 1] = Math.min(arr[i - j + n - 1], temp[j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            int[] temp = new int[m + 1];
            temp[0] = Integer.MAX_VALUE;
            for (int j = 0; j < m; ++j) {
                temp[j + 1] = matrix[j][i];
            }
            for (int j = 0; j < m; ++j) {
                arr[m - j + i - 1] = Math.min(arr[m - j + i - 1], temp[j]);
            }
        }
        for (int i = 0; i < m + n - 1; ++i) {
            if (arr[i] != Integer.MAX_VALUE) {
                for (int j = i + 1; j < m + n - 1; ++j) {
                    if (arr[j] != Integer.MAX_VALUE && arr[i] != arr[j]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
    
