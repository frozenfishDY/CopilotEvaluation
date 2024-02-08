/**https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/ */
//Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
//Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
//Notice that you can return the vertices in any order.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findSmallestSetOfVertices = function(n, edges) {
    let res = new Array(n).fill(0);
    for (let edge of edges) {
        res[edge[1]] = 1;
    }
    let ans = [];
    for (let i = 0; i < n; i++) {
        if (res[i] === 0) {
            ans.push(i);
        }
    }
    return ans;
    
};

    