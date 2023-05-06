/**https://leetcode.com/problems/contain-virus/ */
//A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
//The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
//Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.
//Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.


class ContainVirus {
    public int containVirus(int[][] isInfected) {
        int m = isInfected.length, n = isInfected[0].length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = 0;
        while (true) {
            int max = 0, maxI = -1, maxJ = -1;
            boolean[][] visited = new boolean[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        int[] count = new int[1];
                        int[] wall = new int[1];
                        dfs(isInfected, i, j, visited, count, wall);
                        if (count[0] > max) {
                            max = count[0];
                            maxI = i;
                            maxJ = j;
                        }
                    }
                }
            }
            if (max == 0) {
                break;
            }
            visited = new boolean[m][n];
            dfs(isInfected, maxI, maxJ, visited, new int[1], new int[1]);
            res += max;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 2) {
                        isInfected[i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 3) {
                        for (int[] dir : dirs) {
                            int x = i + dir[0], y = j + dir[1];
                            if (x >= 0 && x < m && y >= 0 && y < n && isInfected[x][y] == 0) {
                                isInfected[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        return res;
        
    }
}
     
    