/**https://leetcode.com/problems/increment-submatrices-by-one/ */
//You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
//You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:
//Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for for all row1i <= x <= row2i and col1i <= y <= col2i.
//Return the matrix mat after performing every query.


class IncrementSubmatricesByOne {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] res = new int[n][n];
        for(int[] query : queries){
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];
            res[row1][col1]++;
            if(row2 + 1 < n){
                res[row2 + 1][col1]--;
            }
            if(col2 + 1 < n){
                res[row1][col2 + 1]--;
            }
            if(row2 + 1 < n && col2 + 1 < n){
                res[row2 + 1][col2 + 1]++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                res[i][j] += res[i][j - 1];
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                res[i][j] += res[i - 1][j];
            }
        }
        return res;
        
        
    }
}

    