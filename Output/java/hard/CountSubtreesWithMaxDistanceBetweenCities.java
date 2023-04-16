/**https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/ */
//There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.
//A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.
//For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.
//Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.
//Notice that the distance between the two cities is the number of edges in the path between them.


class CountSubtreesWithMaxDistanceBetweenCities {
    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        int[] res = new int[n - 1];
        int[][] graph = new int[n][n];
        for(int[] edge : edges){
            graph[edge[0] - 1][edge[1] - 1] = 1;
            graph[edge[1] - 1][edge[0] - 1] = 1;
        }
        for(int i = 1; i < (1 << n); i++){
            int[] dist = new int[n];
            Arrays.fill(dist, -1);
            int count = 0;
            int max = 0;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    count++;
                    dist[j] = 0;
                }
            }
            if(count <= 1){
                continue;
            }
            Queue<Integer> queue = new LinkedList<>();
            for(int j = 0; j < n; j++){
                if(dist[j] == 0){
                    queue.offer(j);
                }
            }
            while(!queue.isEmpty()){
                int cur = queue.poll();
                for(int j = 0; j < n; j++){
                    if(graph[cur][j] == 1 && dist[j] == -1){
                        dist[j] = dist[cur] + 1;
                        max = Math.max(max, dist[j]);
                        queue.offer(j);
                    }
                }
            }
            if(count == max + 1){
                res[max - 1]++;
            }
        }
        return res;
        
    }
}
     
    