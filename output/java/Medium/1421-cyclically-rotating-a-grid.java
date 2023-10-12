/**https://leetcode.com/problems/cyclically-rotating-a-grid/ */
//You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k._x000D_
//_x000D_
//The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:_x000D_
//_x000D_
//_x000D_
//_x000D_
//A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:_x000D_
//_x000D_
//Return the matrix after applying k cyclic rotations to it._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[40,10],[30,20]], k = 1_x000D_
//Output: [[10,20],[40,30]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//  _x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2_x000D_
//Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	m == grid.length_x000D_
//	n == grid[i].length_x000D_
//	2 <= m, n <= 50_x000D_
//	Both m and n are even integers._x000D_
//	1 <= grid[i][j] <= 5000_x000D_
//	1 <= k <= 109_x000D_
class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][] res = new int[m][n];
        int l = 0, r = n - 1, u = 0, d = m - 1;
        while (l < r && u < d) {
            int len = (r - l + 1) * 2 + (d - u - 1) * 2;
            int[] arr = new int[len];
            int idx = 0;
            for (int i = l; i <= r; i++) {
                arr[idx++] = grid[u][i];
            }
            for (int i = u + 1; i <= d; i++) {
                arr[idx++] = grid[i][r];
            }
            for (int i = r - 1; i >= l; i--) {
                arr[idx++] = grid[d][i];
            }
            for (int i = d - 1; i >= u + 1; i--) {
                arr[idx++] = grid[i][l];
            }
            int offset = k % len;
            idx = 0;
            for (int i = l; i <= r; i++) {
                res[u][i] = arr[(idx + offset) % len];
                idx++;
            }
            for (int i = u + 1; i <= d; i++) {
                res[i][r] = arr[(idx + offset) % len];
                idx++;
            }
            for (int i = r - 1; i >= l; i--) {
                res[d][i] = arr[(idx + offset) % len];
                idx++;
            }
            for (int i = d - 1; i >= u + 1; i--) {
                res[i][l] = arr[(idx + offset) % len];
                idx++;
            }
            l++;
            r--;
            u++;
            d--;
        }
        if (l == r) {
            for (int i = u; i <= d; i++) {
                res[i][l] = grid[i][l];
            }
        } else if (u == d) {
            for (int i = l; i <= r; i++) {
                res[u][i] = grid[u][i];
            }
        }
        return res;
    }
}