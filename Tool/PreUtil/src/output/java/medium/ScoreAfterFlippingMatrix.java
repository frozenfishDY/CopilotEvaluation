/**https://leetcode.com/problems/score-after-flipping-matrix/ */
//You are given an m x n binary matrix grid.
//A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
//Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//Return the highest possible score after making any number of moves (including zero moves).


class ScoreAfterFlippingMatrix {
    public int matrixScore(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int res = m * (1 << (n - 1));
        for(int j = 1; j < n; j++){
            int ones = 0;
            for(int i = 0; i < m; i++){
                if(grid[i][0] == 1){
                    ones += grid[i][j];
                }else{
                    ones += 1 - grid[i][j];
                }
            }
            int k = Math.max(ones, m - ones);
            res += k * (1 << (n - j - 1));
        }
        return res;
        
        
        
    }
}

    