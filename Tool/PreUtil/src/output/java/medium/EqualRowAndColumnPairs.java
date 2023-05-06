/**https://leetcode.com/problems/equal-row-and-column-pairs/ */
//Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
//A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).


class EqualRowAndColumnPairs {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        int[][] row = new int[n][n];
        int[][] col = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                row[i][j] = -1;
                col[i][j] = -1;
            }
        }
        for(int i = 0; i < n; i++){
            row[i][0] = grid[i][0];
            col[0][i] = grid[0][i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                row[i][j] = row[i][j-1] & grid[i][j];
                col[j][i] = col[j-1][i] & grid[j][i];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(row[i][j] == col[j][i]){
                    count++;
                }
            }
        }
        return count;
        
    }
}
     
    