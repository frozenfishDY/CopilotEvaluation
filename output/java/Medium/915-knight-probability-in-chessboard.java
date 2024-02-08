/**https://leetcode.com/problems/knight-probability-in-chessboard/ */
//On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
//A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


class KnightProbabilityInChessboard {
    public double knightProbability(int n, int k, int row, int column) {
        double[][] dp = new double[n][n];
        dp[row][column] = 1;
        int[][] dirs = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
        for(int i = 0; i < k; i++){
            double[][] temp = new double[n][n];
            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    for(int[] dir : dirs){
                        int nr = r + dir[0];
                        int nc = c + dir[1];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                            temp[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = temp;
        }
        double res = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                res += dp[r][c];
            }
        }
        return res;
        
        
    }
}

    