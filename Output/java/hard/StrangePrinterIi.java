/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.


class StrangePrinterIi {
    public boolean isPrintable(int[][] targetGrid) {
        int m = targetGrid.length;
        int n = targetGrid[0].length;
        int[] minRow = new int[61];
        int[] maxRow = new int[61];
        int[] minCol = new int[61];
        int[] maxCol = new int[61];
        Arrays.fill(minRow, Integer.MAX_VALUE);
        Arrays.fill(maxRow, Integer.MIN_VALUE);
        Arrays.fill(minCol, Integer.MAX_VALUE);
        Arrays.fill(maxCol, Integer.MIN_VALUE);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int color = targetGrid[i][j];
                minRow[color] = Math.min(minRow[color], i);
                maxRow[color] = Math.max(maxRow[color], i);
                minCol[color] = Math.min(minCol[color], j);
                maxCol[color] = Math.max(maxCol[color], j);
            }
        }
        boolean[] visited = new boolean[61];
        boolean[] inStack = new boolean[61];
        for(int i = 1; i <= 60; i++){
            if(minRow[i] == Integer.MAX_VALUE){
                continue;
            }
            if(!dfs(targetGrid, minRow, maxRow, minCol, maxCol, visited, inStack, i)){
                return false;
            }
        }
        return true;
        
    }
}
     
    