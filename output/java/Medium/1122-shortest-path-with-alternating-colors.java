/**https://leetcode.com/problems/shortest-path-with-alternating-colors/ */
//You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
//You are given two arrays redEdges and blueEdges where:
//	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
//	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
//Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
// 
//Example 1:
//Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
//Output: [0,1,-1]
//Example 2:
//Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
//Output: [0,1,-1]
// 
//Constraints:
//	1 <= n <= 100
//	0 <= redEdges.length, blueEdges.length <= 400
//	redEdges[i].length == blueEdges[j].length == 2
//	0 <= ai, bi, uj, vj < n
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) { 
      // 1. create a graph
		// 2. create a set to store the visited nodes
		// 3. create a queue to store the nodes to be visited
		// 4. create an array to store the answer
		// 5. add the 0 node to the queue
		// 6. add the 0 node to the set
		// 7. while the queue is not empty
		// 7.1 get the size of the queue
		// 7.2 for each node in the queue
		// 7.2.1 for each edge of the node
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int[] redEdge: redEdges) {
            graph.putIfAbsent(redEdge[0], new ArrayList<>());
            graph.get(redEdge[0]).add(redEdge[1]);
        }
        for(int[] blueEdge: blueEdges) {
            graph.putIfAbsent(blueEdge[0], new ArrayList<>());
            graph.get(blueEdge[0]).add(blueEdge[1]);
        }
        Set<Integer> set = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        queue.offer(0);
        set.add(0);
        ans[0] = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                int node = queue.poll();
                if(graph.containsKey(node)) {
                    for(int next: graph.get(node)) {
                        if(!set.contains(next)) {
                            set.add(next);
                            queue.offer(next);
                            ans[next] = ans[node] + 1;
                        }
                    }
                }
            }
        }
        return ans;
		
    }
}