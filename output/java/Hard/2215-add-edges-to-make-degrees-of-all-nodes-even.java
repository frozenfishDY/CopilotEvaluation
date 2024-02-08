/**https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/ */
//There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.
//You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.
//Return true if it is possible to make the degree of each node in the graph even, otherwise return false.
//The degree of a node is the number of edges connected to it.


class AddEdgesToMakeDegreesOfAllNodesEven {
    public boolean isPossible(int n, List<List<Integer>> edges) {
        int[] degree = new int[n + 1];
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(List<Integer> edge : edges){
            int u = edge.get(0);
            int v = edge.get(1);
            degree[u]++;
            degree[v]++;
            map.computeIfAbsent(u, k -> new HashSet<>()).add(v);
            map.computeIfAbsent(v, k -> new HashSet<>()).add(u);
        }
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 1; i <= n; i++){
            if(degree[i] % 2 == 1){
                queue.offer(i);
            }
        }
        while(!queue.isEmpty()){
            int u = queue.poll();
            if(degree[u] % 2 == 1){
                if(!map.containsKey(u)){
                    return false;
                }
                int v = map.get(u).iterator().next();
                map.get(v).remove(u);
                degree[v]--;
                if(degree[v] % 2 == 1){
                    queue.offer(v);
                }
            }
        }
        return true;
        
    }
}
     
    