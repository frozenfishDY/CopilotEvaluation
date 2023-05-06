/**https://leetcode.com/problems/cat-and-mouse/ */
//A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.
//The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.
//The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.
//During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].
//Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)
//Then, the game can end in three ways:
//If ever the Cat occupies the same node as the Mouse, the Cat wins.
//If ever the Mouse reaches the Hole, the Mouse wins.
//If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
//Given a graph, and assuming both players play optimally, return
//1 if the mouse wins the game,
//2 if the cat wins the game, or
//0 if the game is a draw.


class CatAndMouse {
    public int catMouseGame(int[][] graph) {
        int n = graph.length;
        int[][][] color = new int[n][n][2];
        int[][][] degree = new int[n][n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i][j][0] = graph[i].length;
                degree[i][j][1] = graph[j].length;
                for (int k : graph[j]) {
                    if (k == 0) {
                        degree[i][j][1]--;
                    }
                }
            }
        }
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < 2; t++) {
                color[0][i][t] = 2;
                queue.offer(new int[]{0, i, t, 2});
                if (i > 0) {
                    color[i][i][t] = 1;
                    queue.offer(new int[]{i, i, t, 1});
                }
            }
        }
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int i = cur[0], j = cur[1], t = cur[2], c = cur[3];
            for (int k : graph[t == 0 ? i : j]) {
                if (c == 1) {
                    if (color[k][j][1 - t] == 0) {
                        color[k][j][1 - t] = 1;
                        queue.offer(new int[]{k, j, 1 - t, 1});
                    }
                } else {
                    degree[k][j][1 - t]--;
                    if (degree[k][j][1 - t] == 0 && color[k][j][1 - t] == 0) {
                        color[k][j][1 - t] = 2;
                        queue.offer(new int[]{k, j, 1 - t, 2});
                    }
                }
            }
        }
        return color[1][2][0];
        
    }
}
     
    