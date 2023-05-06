/**https://leetcode.com/problems/largest-submatrix-with-rearrangements/ */
//You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
//Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.


class LargestSubmatrixWithRearrangements {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] height = new int[n];
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    height[j] = 0;
                }else{
                    height[j]++;
                }
            }
            int[] temp = Arrays.copyOf(height, n);
            Arrays.sort(temp);
            for(int j = 0; j < n; j++){
                res = Math.max(res, temp[j] * (n - j));
            }
        }
        return res;
        
    }
}
     
    