/**https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/ */
//You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
//The score of a path between two cities is defined as the minimum distance of a road in this path.
//Return the minimum possible score of a path between cities 1 and n.
//Note:
//A path is a sequence of roads between two cities.
//It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
//The test cases are generated such that there is at least one path between 1 and n.


class MinimumScoreOfAPathBetweenTwoCities {
    public int minScore(int n, int[][] roads) {
        int[][] g = new int[n][n];
        for(int i = 0; i < n; i++){
            Arrays.fill(g[i], Integer.MAX_VALUE);
        }
        for(int[] r : roads){
            g[r[0] - 1][r[1] - 1] = r[2];
            g[r[1] - 1][r[0] - 1] = r[2];
        }
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        boolean[] visited = new boolean[n];
        for(int i = 0; i < n; i++){
            int min = Integer.MAX_VALUE;
            int u = -1;
            for(int j = 0; j < n; j++){
                if(!visited[j] && dist[j] < min){
                    min = dist[j];
                    u = j;
                }
            }
            if(u == -1){
                break;
            }
            visited[u] = true;
            for(int v = 0; v < n; v++){
                if(!visited[v] && g[u][v] != Integer.MAX_VALUE){
                    dist[v] = Math.min(dist[v], Math.max(dist[u], g[u][v]));
                }
            }
        }
        return dist[n - 1];
        
        
        
    }
}

    