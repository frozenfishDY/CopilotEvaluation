/**https://leetcode.com/problems/stamping-the-grid/ */
//You are given an m x n binary matrix grid where each cell is either 0 (empty) or 1 (occupied).
//You are then given stamps of size stampHeight x stampWidth. We want to fit the stamps such that they follow the given restrictions and requirements:
//Cover all the empty cells.
//Do not cover any of the occupied cells.
//We can put as many stamps as we want.
//Stamps can overlap with each other.
//Stamps are not allowed to be rotated.
//Stamps must stay completely inside the grid.
//Return true if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return false.


class StampingTheGrid {
    public boolean possibleToStamp(int[][] grid, int stampHeight, int stampWidth) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] stamp = new int[stampHeight][stampWidth];
        for (int i = 0; i < stampHeight; i++) {
            for (int j = 0; j < stampWidth; j++) {
                stamp[i][j] = 1;
            }
        }
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = grid[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][j] == 0) {
                    if (i + stampHeight <= m && j + stampWidth <= n) {
                        boolean match = true;
                        for (int k = 0; k < stampHeight; k++) {
                            for (int l = 0; l < stampWidth; l++) {
                                if (res[i + k][j + l] != stamp[k][l]) {
                                    match = false;
                                    break;
                                }
                            }
                            if (!match) {
                                break;
                            }
                        }
                        if (match) {
                            for (int k = 0; k < stampHeight; k++) {
                                for (int l = 0; l < stampWidth; l++) {
                                    res[i + k][j + l] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
        
    }
}
     
    