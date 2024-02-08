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
/**
 * @param {number} n
 * @param {number[][]} redEdges
 * @param {number[][]} blueEdges
 * @return {number[]}
 */
var shortestAlternatingPaths = function(n, redEdges, blueEdges) {
    var ans = Array(n).fill(-1);
	var redAdj = Array(n).fill(null).map(() => []);
	var blueAdj = Array(n).fill(null).map(() => []);
	for (var i = 0; i < redEdges.length; i++) {
		redAdj[redEdges[i][0]].push(redEdges[i][1]);
	}
	for (var i = 0; i < blueEdges.length; i++) {
		blueAdj[blueEdges[i][0]].push(blueEdges[i][1]);
	}
	var queue = [[0, 0], [0, 1]];
	var visited = Array(n).fill(null).map(() => Array(2).fill(false));
	visited[0][0] = true;
	visited[0][1] = true;
	var steps = 0;
	while (queue.length > 0) {
		var len = queue.length;
		for (var i = 0; i < len; i++) {
			var cur = queue.shift();
			var color = cur[1];
			var adj = color == 0 ? blueAdj[cur[0]] : redAdj[cur[0]];
			for (var j = 0; j < adj.length; j++) {
				var next = adj[j];
				if (visited[next][1 - color]) {
					continue;
				}
				visited[next][1 - color] = true;
				if (ans[next] == -1) {
					ans[next] = steps + 1;
				}
				queue.push([next, 1 - color]);
			}
		}
		steps++;
	}
	return ans;
};