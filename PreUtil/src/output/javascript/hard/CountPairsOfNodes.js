/**https://leetcode.com/problems/count-pairs-of-nodes/ */
//You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
//Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
//The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
//a < b
//incident(a, b) > queries[j]
//Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
//Note that there can be multiple edges between the same two nodes.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} queries
 * @return {number[]}
 */
var countPairs = function(n, edges, queries) {
    let result = [];
    let edgeCount = new Array(n + 1).fill(0);
    let edgeMap = new Map();
    for (let i = 0; i < edges.length; i++) {
        let edge = edges[i];
        let node1 = edge[0];
        let node2 = edge[1];
        let key = node1 + '-' + node2;
        if (!edgeMap.has(key)) {
            edgeMap.set(key, 1);
            edgeCount[node1]++;
            edgeCount[node2]++;
        }
    }
    for (let i = 0; i < queries.length; i++) {
        let count = 0;
        for (let j = 1; j <= n; j++) {
            for (let k = j + 1; k <= n; k++) {
                let key = j + '-' + k;
                if (edgeMap.has(key)) {
                    if (edgeCount[j] + edgeCount[k] > queries[i]) {
                        count++;
                    }
                }
            }
        }
        result.push(count);
    }
    return result;
    
};

    