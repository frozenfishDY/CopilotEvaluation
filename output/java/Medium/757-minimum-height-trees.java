/**https://leetcode.com/problems/minimum-height-trees/ */
//A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
//Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
//Return a list of all MHTs' root labels. You can return the answer in any order.
//The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


class MinimumHeightTrees {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> result = new ArrayList<>();
        if(n == 1){
            result.add(0);
            return result;
        }
        List<Set<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++){
            graph.add(new HashSet<>());
        }
        for(int[] edge : edges){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < n; i++){
            if(graph.get(i).size() == 1){
                queue.offer(i);
            }
        }
        while(n > 2){
            int size = queue.size();
            n -= size;
            for(int i = 0; i < size; i++){
                int node = queue.poll();
                int neighbor = graph.get(node).iterator().next();
                graph.get(neighbor).remove(node);
                if(graph.get(neighbor).size() == 1){
                    queue.offer(neighbor);
                }
            }
        }
        while(!queue.isEmpty()){
            result.add(queue.poll());
        }
        return result;
        
        
        
    }
}

    