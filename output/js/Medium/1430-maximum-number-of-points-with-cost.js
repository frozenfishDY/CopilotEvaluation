/**https://leetcode.com/problems/maximum-number-of-points-with-cost/ */
//You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.
//To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
//However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
//Return the maximum number of points you can achieve.
//abs(x) is defined as:
//	x for x >= 0.
//	-x for x < 0.
// 
//Example 1: 
//Input: points = [[1,2,3],[1,5,1],[3,1,1]]
//Output: 9
//Explanation:
//The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
//You add 3 + 5 + 3 = 11 to your score.
//However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
//Your final score is 11 - 2 = 9.
//Example 2:
//Input: points = [[1,5],[2,3],[4,2]]
//Output: 11
//Explanation:
//The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
//You add 5 + 3 + 4 = 12 to your score.
//However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
//Your final score is 12 - 1 = 11.
// 
//Constraints:
//	m == points.length
//	n == points[r].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	0 <= points[r][c] <= 105
/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    let m = points.length;
    let n = points[0].length;
    let dp = points[0];
    for(let i = 1; i < m; i++){
        let left = new Array(n).fill(0);
        let right = new Array(n).fill(0);
        left[0] = dp[0];
        for(let j = 1; j < n; j++){
            left[j] = Math.max(left[j - 1] - 1, dp[j]);
        }
        right[n - 1] = dp[n - 1];
        for(let j = n - 2; j >= 0; j--){
            right[j] = Math.max(right[j + 1] - 1, dp[j]);
        }
        for(let j = 0; j < n; j++){
            dp[j] = points[i][j] + Math.max(left[j], right[j]);
        }
    }
    return Math.max(...dp);
};