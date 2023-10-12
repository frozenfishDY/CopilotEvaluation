/**https://leetcode.com/problems/diagonal-traverse/ */
//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,4,7,5,3,6,8,9]
//Example 2:
//Input: mat = [[1,2],[3,4]]
//Output: [1,2,3,4]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	-105 <= mat[i][j] <= 105
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] result = new int[m * n];
        int index = 0;
        int row = 0, col = 0;
        boolean up = true;
        while (index < m * n) {
            result[index++] = mat[row][col];
            if (up) {
                if (row - 1 >= 0 && col + 1 < n) {
                    row--;
                    col++;
                } else if (row - 1 < 0 && col + 1 < n) {
                    col++;
                    up = false;
                } else if (row - 1 >= 0 && col + 1 >= n) {
                    row++;
                    up = false;
                }
            } else {
                if (row + 1 < m && col - 1 >= 0) {
                    row++;
                    col--;
                } else if (row + 1 < m && col - 1 < 0) {
                    row++;
                    up = true;
                } else if (row + 1 >= m && col - 1 >= 0) {
                    col++;
                    up = true;
                }
            }
        }
        return result;
    }
}