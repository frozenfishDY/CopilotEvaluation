/**https://leetcode.com/problems/sort-the-matrix-diagonally/ */
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
//Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.


class SortTheMatrixDiagonally {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] dp = new int[m + 1][n + 1];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = mat[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= m; i++){
            int[] arr = new int[Math.min(m - i + 1, n)];
            int k = 0;
            for(int j = 1; j <= n; j++){
                if(i + j - 1 <= m){
                    arr[k++] = dp[i + j - 1][j];
                }
            }
            Arrays.sort(arr);
            k = 0;
            for(int j = 1; j <= n; j++){
                if(i + j - 1 <= m){
                    dp[i + j - 1][j] = arr[k++];
                }
            }
        }
        for(int j = 2; j <= n; j++){
            int[] arr = new int[Math.min(n - j + 1, m)];
            int k = 0;
            for(int i = 1; i <= m; i++){
                if(i + j - 1 <= n){
                    arr[k++] = dp[i][i + j - 1];
                }
            }
            Arrays.sort(arr);
            k = 0;
            for(int i = 1; i <= m; i++){
                if(i + j - 1 <= n){
                    dp[i][i + j - 1] = arr[k++];
                }
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                mat[i - 1][j - 1] = dp[i][j];
            }
        }
        return mat;
        
    }
}

    