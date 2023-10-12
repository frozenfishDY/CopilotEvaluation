/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1._x000D_
//_x000D_
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj._x000D_
//_x000D_
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path._x000D_
//_x000D_
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]_x000D_
//Output: 3_x000D_
//Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image)._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: colors = "a", edges = [[0,0]]_x000D_
//Output: -1_x000D_
//Explanation: There is a cycle from 0 to 0._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	n == colors.length_x000D_
//	m == edges.length_x000D_
//	1 <= n <= 105_x000D_
//	0 <= m <= 105_x000D_
//	colors consists of lowercase English letters._x000D_
//	0 <= aj, bj < n_x000D_
/**_x000D_
 * @param {string} colors_x000D_
 * @param {number[][]} edges_x000D_
 * @return {number}_x000D_
 */_x000D_
var largestPathValue = function(colors, edges) {_x000D_
    _x000D_
};