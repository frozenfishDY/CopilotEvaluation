/**https://leetcode.com/problems/grid-illumination/ */
//There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
//You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
//When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
//You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
//Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.


class GridIllumination {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        int[] ans = new int[queries.length];
        Map<Integer, Integer> row = new HashMap<>();
        Map<Integer, Integer> col = new HashMap<>();
        Map<Integer, Integer> diag1 = new HashMap<>();
        Map<Integer, Integer> diag2 = new HashMap<>();
        Set<Integer> lampSet = new HashSet<>();
        for (int[] lamp : lamps) {
            int x = lamp[0];
            int y = lamp[1];
            row.put(x, row.getOrDefault(x, 0) + 1);
            col.put(y, col.getOrDefault(y, 0) + 1);
            diag1.put(x - y, diag1.getOrDefault(x - y, 0) + 1);
            diag2.put(x + y, diag2.getOrDefault(x + y, 0) + 1);
            lampSet.add(x * n + y);
        }
        int[][] dirs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (row.getOrDefault(x, 0) > 0 || col.getOrDefault(y, 0) > 0 || diag1.getOrDefault(x - y, 0) > 0 || diag2.getOrDefault(x + y, 0) > 0) {
                ans[i] = 1;
            }
            for (int[] dir : dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if (lampSet.contains(newX * n + newY)) {
                    row.put(newX, row.get(newX) - 1);
                    col.put(newY, col.get(newY) - 1);
                    diag1.put(newX - newY, diag1.get(newX - newY) - 1);
                    diag2.put(newX + newY, diag2.get(newX + newY) - 1);
                    lampSet.remove(newX * n + newY);
                }
            }
        }
        return ans;
        
    }
}
     
    