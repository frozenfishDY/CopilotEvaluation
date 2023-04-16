/**https://leetcode.com/problems/count-unguarded-cells-in-the-grid/ */
//You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
//A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
//Return the number of unoccupied cells that are not guarded.


class CountUnguardedCellsInTheGrid {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];
        for(int[] guard : guards){
            int x = guard[0];
            int y = guard[1];
            grid[x][y] = 1;
            for(int i = x - 1; i >= 0; i--){
                if(grid[i][y] == 2){
                    break;
                }
                grid[i][y] = 1;
            }
            for(int i = x + 1; i < m; i++){
                if(grid[i][y] == 2){
                    break;
                }
                grid[i][y] = 1;
            }
            for(int i = y - 1; i >= 0; i--){
                if(grid[x][i] == 2){
                    break;
                }
                grid[x][i] = 1;
            }
            for(int i = y + 1; i < n; i++){
                if(grid[x][i] == 2){
                    break;
                }
                grid[x][i] = 1;
            }
        }
        for(int[] wall : walls){
            int x = wall[0];
            int y = wall[1];
            grid[x][y] = 2;
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
        
    }
}
     
    