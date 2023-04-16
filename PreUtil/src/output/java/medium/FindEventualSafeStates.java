/**https://leetcode.com/problems/find-eventual-safe-states/ */
//There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
//A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
//Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


class FindEventualSafeStates {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        List<Integer> res = new ArrayList<>();
        int[] color = new int[n];
        for(int i = 0; i < n; i++){
            if(dfs(graph, i, color)){
                res.add(i);
            }
        }
        return res;
        
        
    }
}

    