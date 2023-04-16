/**https://leetcode.com/problems/minimum-height-trees/ */
//A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
//Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
//Return a list of all MHTs' root labels. You can return the answer in any order.
//The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    if(n == 1){
        return [0];
    }
    let graph = new Array(n);
    for(let i = 0; i < n; i++){
        graph[i] = [];
    }
    for(let i = 0; i < edges.length; i++){
        let u = edges[i][0];
        let v = edges[i][1];
        graph[u].push(v);
        graph[v].push(u);
    }
    let leaves = [];
    for(let i = 0; i < n; i++){
        if(graph[i].length == 1){
            leaves.push(i);
        }
    }
    let remainingNodes = n;
    while(remainingNodes > 2){
        remainingNodes -= leaves.length;
        let newLeaves = [];
        for(let i = 0; i < leaves.length; i++){
            let u = leaves[i];
            for(let j = 0; j < graph[u].length; j++){
                let v = graph[u][j];
                let index = graph[v].indexOf(u);
                graph[v].splice(index, 1);
                if(graph[v].length == 1){
                    newLeaves.push(v);
                }
            }
        }
        leaves = newLeaves;
    }
    return leaves;
    
};

    