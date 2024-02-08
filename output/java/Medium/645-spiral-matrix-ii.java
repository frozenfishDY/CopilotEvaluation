/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.


class SpiralMatrixIi {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int num = 1;
        while(left <= right && top <= bottom){
            for(int i = left; i <= right; i++){
                res[top][i] = num++;
            }
            top++;
            for(int i = top; i <= bottom; i++){
                res[i][right] = num++;
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    res[bottom][i] = num++;
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    res[i][left] = num++;
                }
                left++;
            }
        }
        return res;
        
    }
}

    