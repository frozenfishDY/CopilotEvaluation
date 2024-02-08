/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '' is represented as '\'.


class RegionsCutBySlashes {
    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int[][] g = new int[n * 3][n * 3];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i].charAt(j) == '/'){
                    g[i * 3][j * 3 + 2] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3] = 1;
                }
                else if(grid[i].charAt(j) == '\\'){
                    g[i * 3][j * 3] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n * 3; i++){
            for(int j = 0; j < n * 3; j++){
                if(g[i][j] == 0){
                    dfs(g, i, j);
                    res++;
                }
            }
        }
        return res;
        
        
        
    }
}

    