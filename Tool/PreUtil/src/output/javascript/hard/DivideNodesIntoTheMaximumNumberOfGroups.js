/**https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/ */
//You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
//You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
//Divide the nodes of the graph into m groups (1-indexed) such that:
//Each node in the graph belongs to exactly one group.
//For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
//Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var magnificentSets = function(n, edges) {
    let result = 0;
    let edgeMap = new Map();
    for (let i = 0; i < edges.length; i++) {
        let edge = edges[i];
        let node1 = edge[0];
        let node2 = edge[1];
        let key = node1 + '-' + node2;
        if (!edgeMap.has(key)) {
            edgeMap.set(key, 1);
        }
    }
    let visited = new Array(n + 1).fill(0);
    let queue = [];
    for (let i = 1; i <= n; i++) {
        if (visited[i] === 0) {
            queue.push(i);
            visited[i] = 1;
            while (queue.length > 0) {
                let node = queue.shift();
                for (let j = 1; j <= n; j++) {
                    let key = node + '-' + j;
                    if (edgeMap.has(key) && visited[j] === 0) {
                        queue.push(j);
                        visited[j] = 1;
                    }
                }
            }
            result++;
        }
    }
    return result;
    
    
};

    