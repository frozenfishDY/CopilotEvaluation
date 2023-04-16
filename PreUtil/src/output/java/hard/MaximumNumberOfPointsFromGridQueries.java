/**https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/ */
//You are given an m x n integer matrix grid and an array queries of size k.
//Find an array answer of size k such that for each integer queres[i] you start in the top left cell of the matrix and repeat the following process:
//    If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//    Otherwise, you do not get any points, and you end this process.
//After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//Return the resulting array answer.


class MaximumNumberOfPointsFromGridQueries {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] prefix = new int[m + 1][n + 1];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        int[] res = new int[queries.length];
        for(int i = 0; i < queries.length; i++){
            int x = queries[i] / n;
            int y = queries[i] % n;
            int l = 0;
            int r = Math.min(x, y) + 1;
            while(l < r){
                int mid = l + (r - l) / 2;
                int sum = prefix[x + 1][y + 1] - prefix[x + 1][y - mid] - prefix[x - mid][y + 1] + prefix[x - mid][y - mid];
                if(sum > 0){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            res[i] = l - 1;
        }
        return res;
        
    }
}
     
    