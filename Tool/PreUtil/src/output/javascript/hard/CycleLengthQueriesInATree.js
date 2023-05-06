/**https://leetcode.com/problems/cycle-length-queries-in-a-tree/ */
//You are given an integer n. There is a complete binary tree with 2^(n - 1) nodes. The root of that tree is the node with the value 1, and every node with a value val in the range [1, 2n - 1 - 1] has two children where:
//The left node has the value 2 * val, and
//The right node has the value 2 * val + 1.
//You are also given a 2D integer array queries of length m, where queries[i] = [ai, bi]. For each query, solve the following problem:
//Add an edge between the nodes with values ai and bi.
//Find the length of the cycle in the graph.
//Remove the added edge between nodes with values ai and bi.
//Note that:
//A cycle is a path that starts and ends at the same node, and each edge in the path is visited only once.
//The length of a cycle is the number of edges visited in the cycle.
//There could be multiple edges between two nodes in the tree after adding the edge of the query.
//Return an array answer of length m where answer[i] is the answer to the ith query.


/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[]}
 */
var cycleLengthQueries = function(n, queries) {
    let m = queries.length;
    let ans = new Array(m).fill(-1);
    let edges = new Array(m);
    for(let i = 0; i < m; i++){
        edges[i] = [queries[i][0], queries[i][1], i];
    }
    edges.sort((a, b) => a[0] - b[0]);
    let uf = new UnionFind(n);
    let max = 1;
    let map = new Map();
    for(let i = 0; i < m; i++){
        let [x, y, idx] = edges[i];
        if(!map.has(x)){
            map.set(x, max);
            max++;
        }
        if(!map.has(y)){
            map.set(y, max);
            max++;
        }
        x = map.get(x);
        y = map.get(y);
        if(uf.union(x, y)){
            ans[idx] = uf.size[x];
        }
    }
    return ans;
    
    
};

    