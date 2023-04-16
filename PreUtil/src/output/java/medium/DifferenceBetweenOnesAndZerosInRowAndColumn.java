/**https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/ */
//You are given a 0-indexed m x n binary matrix grid.
//A 0-indexed m x n difference matrix diff is created with the following procedure:
//Let the number of ones in the ith row be onesRowi.
//Let the number of ones in the jth column be onesColj.
//Let the number of zeros in the ith row be zerosRowi.
//Let the number of zeros in the jth column be zerosColj.
//diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
//Return the difference matrix diff.


class DifferenceBetweenOnesAndZerosInRowAndColumn {
    public int[][] onesMinusZeros(int[][] grid) {
        int[][] diff = new int[grid.length][grid[0].length];
        int[] onesRow = new int[grid.length];
        int[] onesCol = new int[grid[0].length];
        int[] zerosRow = new int[grid.length];
        int[] zerosCol = new int[grid[0].length];
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    onesRow[i]++;
                    onesCol[j]++;
                }else{
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
            }
        }
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return diff;
        
    }
}

    