/**https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/ */
//You are given an m x n integer matrix grid​​​.
//A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
//Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
//Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.
// 
//Example 1:
//Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
//Output: [228,216,211]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 20 + 3 + 200 + 5 = 228
//- Red: 200 + 2 + 10 + 4 = 216
//- Green: 5 + 200 + 4 + 2 = 211
//Example 2:
//Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [20,9,8]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 4 + 2 + 6 + 8 = 20
//- Red: 9 (area 0 rhombus in the bottom right corner)
//- Green: 8 (area 0 rhombus in the bottom middle)
//Example 3:
//Input: grid = [[7,7,7]]
//Output: [7]
//Explanation: All three possible rhombus sums are the same, so return [7].
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 105
class Solution {
    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][][] sum = new int[m][n][4];
        sum[0][0][0] = grid[0][0];
        sum[0][0][1] = grid[0][0];
        sum[0][0][2] = grid[0][0];
        sum[0][0][3] = grid[0][0];
        for (int i = 1; i < m; i++) {
            sum[i][0][0] = grid[i][0];
            sum[i][0][1] = grid[i][0];
            sum[i][0][2] = grid[i][0];
            sum[i][0][3] = grid[i][0];
            for (int j = 1; j < n; j++) {
                sum[i][j][0] = sum[i - 1][j - 1][0] + grid[i][j];
                sum[i][j][1] = sum[i - 1][j - 1][1] + grid[i][j];
                sum[i][j][2] = sum[i - 1][j - 1][2] + grid[i][j];
                sum[i][j][3] = sum[i - 1][j - 1][3] + grid[i][j];
            }
        }
        for (int i = 1; i < m; i++) {
            sum[i][n - 1][1] = grid[i][n - 1];
            sum[i][n - 1][2] = grid[i][n - 1];
            sum[i][n - 1][3] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                sum[i][j][1] = sum[i - 1][j + 1][1] + grid[i][j];
                sum[i][j][2] = sum[i - 1][j + 1][2] + grid[i][j];
                sum[i][j][3] = sum[i - 1][j + 1][3] + grid[i][j];
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            sum[i][n - 1][2] = grid[i][n - 1];
            sum[i][n - 1][3] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                sum[i][j][2] = sum[i + 1][j + 1][2] + grid[i][j];
                sum[i][j][3] = sum[i + 1][j + 1][3] + grid[i][j];
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            sum[i][0][3] = grid[i][0];
            for (int j = 1; j < n; j++) {
                sum[i][j][3] = sum[i + 1][j - 1][3] + grid[i][j];
            }
        }
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < m; i++) {
            for (int j = 3; j < n; j++) {
                set.add(sum[i][j][0]);
                set.add(sum[i][j][1]);
                set.add(sum[i][j][2]);
                set.add(sum[i][j][3]);
            }
        }
        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);
        Collections.reverse(list);
        int[] res = new int[Math.min(3, list.size())];
        for (int i = 0; i < res.length; i++) {
            res[i] = list.get(i);
        }
        return res;
    }
}