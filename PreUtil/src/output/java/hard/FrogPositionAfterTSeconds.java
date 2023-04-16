/**https://leetcode.com/problems/frog-position-after-t-seconds/ */
//Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices, it jumps randomly to one of them with the same probability. Otherwise, when the frog can not jump to any unvisited vertex, it jumps forever on the same vertex.
//The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.
//Return the probability that after t seconds the frog is on the vertex target. Answers within 10-5 of the actual answer will be accepted.


class FrogPositionAfterTSeconds {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int[] edge : edges){
            map.putIfAbsent(edge[0], new ArrayList<>());
            map.putIfAbsent(edge[1], new ArrayList<>());
            map.get(edge[0]).add(edge[1]);
            map.get(edge[1]).add(edge[0]);
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        double[] prob = new double[n + 1];
        prob[1] = 1.0;
        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        while(!q.isEmpty()){
            int size = q.size();
            if(t-- == 0) break;
            for(int i = 0; i < size; i++){
                int curr = q.poll();
                int count = 0;
                for(int next : map.get(curr)){
                    if(!visited[next]){
                        count++;
                    }
                }
                for(int next : map.get(curr)){
                    if(!visited[next]){
                        prob[next] = prob[curr] / count;
                        visited[next] = true;
                        q.add(next);
                    }
                }
            }
        }
        return prob[target];
        
    }
}
     
    