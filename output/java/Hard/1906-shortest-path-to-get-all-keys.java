/**https://leetcode.com/problems/shortest-path-to-get-all-keys/ */
//You are given an m x n grid grid where:
//'.' is an empty cell.
//'#' is a wall.
//'@' is the starting point.
//Lowercase letters represent keys.
//Uppercase letters represent locks.
//You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.
//If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.
//For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
//Return the lowest number of moves to acquire all keys. If it is impossible, return -1.


class ShortestPathToGetAllKeys {
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length;
        int n = grid[0].length();
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int[] start = new int[3];
        int keys = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i].charAt(j);
                if (c == '@') {
                    start[0] = i;
                    start[1] = j;
                } else if (c >= 'a' && c <= 'f') {
                    keys++;
                }
            }
        }
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(start);
        Set<String> visited = new HashSet<>();
        visited.add(start[0] + " " + start[1] + " " + 0);
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.poll();
                int x = cur[0];
                int y = cur[1];
                int key = cur[2];
                if (key == (1 << keys) - 1) {
                    return steps;
                }
                for (int[] dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx].charAt(ny) != '#') {
                        int nkey = key;
                        char c = grid[nx].charAt(ny);
                        if (c >= 'a' && c <= 'f') {
                            nkey |= 1 << (c - 'a');
                        }
                        if (c >= 'A' && c <= 'F' && ((nkey >> (c - 'A')) & 1) == 0) {
                            continue;
                        }
                        if (!visited.contains(nx + " " + ny + " " + nkey)) {
                            queue.offer(new int[]{nx, ny, nkey});
                            visited.add(nx + " " + ny + " " + nkey);
                        }
                    }
                }
            }
            steps ++;


            
        
    }
}
}
     
    