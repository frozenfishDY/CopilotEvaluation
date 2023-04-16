/**https://leetcode.com/problems/rank-transform-of-a-matrix/ */
//Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].
//The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:
//The rank is an integer starting from 1.
//If two elements p and q are in the same row or column, then:
//If p < q then rank(p) < rank(q)
//If p == q then rank(p) == rank(q)
//If p > q then rank(p) > rank(q)
//The rank should be as small as possible.
//The test cases are generated so that answer is unique under the given rules.


class RankTransformOfAMatrix {
    public int[][] matrixRankTransform(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        int[][] res = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rowMax[i] = Math.max(rowMax[i], matrix[i][j]);
                colMax[j] = Math.max(colMax[j], matrix[i][j]);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[i][j] = Math.max(rowMax[i], colMax[j]);
            }
        }
        return res;
        
    }
}
     
    