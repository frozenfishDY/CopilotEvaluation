/**https://leetcode.com/problems/reachable-nodes-with-restrictions/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.
//Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
//Note that node 0 will not be a restricted node.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
//Output: 4
//Explanation: The diagram above shows the tree.
//We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
//Example 2:
//Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
//Output: 3
//Explanation: The diagram above shows the tree.
//We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
// 
//Constraints:
//	2 <= n <= 105
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	edges represents a valid tree.
//	1 <= restricted.length < n
//	1 <= restricted[i] < n
//	All the values of restricted are unique.
/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} restricted
 * @return {number}
 */
var reachableNodes = function(n, edges, restricted) {
    let graph = new Map();
    for (let [u, v, w] of edges) {
        if (!graph.has(u)) graph.set(u, []);
        if (!graph.has(v)) graph.set(v, []);
        graph.get(u).push([v, w]);
        graph.get(v).push([u, w]);
    }
    let dist = new Map();
    let pq = [[0, 0]];
    while (pq.length) {
        let [d, u] = pq.pop();
        if (dist.has(u)) continue;
        dist.set(u, d);
        if (graph.has(u)) {
            for (let [v, w] of graph.get(u)) {
                if (dist.has(v)) continue;
                pq.push([d + w + 1, v]);
            }
        }
    }
    let res = 0;
    for (let [u, v, w] of edges) {
        let d1 = dist.has(u) ? dist.get(u) : Infinity;
        let d2 = dist.has(v) ? dist.get(v) : Infinity;
        if (d1 + d2 > w) {
            res += w;
        } else if (d1 + d2 === w) {
            res += Math.min(d1, d2);
        } else {
            res += Math.max(0, w - (d1 - d2));
        }
    }
    for (let u of restricted) {
        if (dist.has(u)) {
            res++;
        } else {
            return -1;
        }
    }
    return res;

};