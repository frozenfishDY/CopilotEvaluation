/**https://leetcode.com/problems/knight-probability-in-chessboard/ */
//On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
//A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


double knightProbability(int n, int k, int row, int column){
    double dp[25][25][101] = {0};
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    dp[row][column][0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < n; l++){
                for(int m = 0; m < 8; m++){
                    int newRow = j + moves[m][0];
                    int newColumn = l + moves[m][1];
                    if(newRow >= 0 && newRow < n && newColumn >= 0 && newColumn < n){
                        dp[newRow][newColumn][i] += dp[j][l][i - 1] / 8;
                    }
                }
            }
        }
    }
    double result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result += dp[i][j][k];
        }
    }
    return result;

}

    