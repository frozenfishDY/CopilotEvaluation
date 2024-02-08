/**https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/ */
//Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
//Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
//Notice that you can return the vertices in any order.


class MinimumNumberOfVerticesToReachAllNodes {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> result = new ArrayList<>();
        int[] inDegree = new int[n];
        for(List<Integer> edge : edges){
            inDegree[edge.get(1)]++;
        }
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                result.add(i);
            }
        }
        return result;
        
    }
}   
     
    