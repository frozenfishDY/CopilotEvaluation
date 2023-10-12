/**https://leetcode.com/problems/critical-connections-in-a-network/ */
//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
//Return all critical connections in the network in any order.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
//Output: [[1,3]]
//Explanation: [[3,1]] is also accepted.
//Example 2:
//Input: n = 2, connections = [[0,1]]
//Output: [[0,1]]
// 
//Constraints:
//	2 <= n <= 105
//	n - 1 <= connections.length <= 105
//	0 <= ai, bi <= n - 1
//	ai != bi
//	There are no repeated connections.
class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        int[] visited = new int[n];
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(List<Integer> connection : connections){
            int from = connection.get(0);
            int to = connection.get(1);
            graph.putIfAbsent(from, new ArrayList<>());
            graph.putIfAbsent(to, new ArrayList<>());
            graph.get(from).add(to);
            graph.get(to).add(from);
        }
        List<List<Integer>> res = new ArrayList<>();
        dfs(graph, visited, -1, 0, 0, res);
        return res;
    }
    private int dfs(Map<Integer, List<Integer>> graph, int[] visited, int from, int cur, int rank, List<List<Integer>> res){
        visited[cur] = rank + 1;
        for(int to : graph.get(cur)){
            if(to == from){
                continue;
            }
            if(visited[to] == 0){
                visited[cur] = Math.min(visited[cur], dfs(graph, visited, cur, to, rank + 1, res));
            }else{
                visited[cur] = Math.min(visited[cur], visited[to]);
            }
        }
        if(visited[cur] == rank + 1 && cur != 0){
            res.add(Arrays.asList(from, cur));
        }
        return visited[cur];
    }
}