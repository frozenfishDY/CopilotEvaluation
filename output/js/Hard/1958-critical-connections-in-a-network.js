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
/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number[][]}
 */
var criticalConnections = function(n, connections) {
    let result = [];
	let visited = new Array(n).fill(false);
	let lowTime = new Array(n).fill(0);
	let time = 0;
	let graph = new Array(n);
	for (let i = 0; i < n; i++) {
		graph[i] = [];
	}
	for (let i = 0; i < connections.length; i++) {
		let [a, b] = connections[i];
		graph[a].push(b);
		graph[b].push(a);
	}
	dfs(0, -1);
	return result;
};
function dfs(current, parent) {
    visited[current] = true;
    lowTime[current] = time++;
    for (let i = 0; i < graph[current].length; i++) {
        let next = graph[current][i];
        if (next === parent) {
            continue;
        }
        if (!visited[next]) {
            dfs(next, current);
            lowTime[current] = Math.min(lowTime[current], lowTime[next]);
            if (lowTime[next] > lowTime[current]) {
                result.push([current, next]);
            }
        } else {
            lowTime[current] = Math.min(lowTime[current], lowTime[next]);
        }
    }
}