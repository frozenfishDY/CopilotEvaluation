/**https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/ */
//There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.
//You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.
//Return true if it is possible to make the degree of each node in the graph even, otherwise return false.
//The degree of a node is the number of edges connected to it.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {boolean}
 */
var isPossible = function(n, edges) {
    let adj = new Array(n + 1).fill(0).map(() => new Array());
    for(let [u, v] of edges){
        adj[u].push(v);
        adj[v].push(u);
    }
    let visited = new Array(n + 1).fill(false);
    let odd = 0;
    let even = 0;
    for(let i = 1; i <= n; i++){
        if(!visited[i]){
            let res = dfs(i, adj, visited);
            if(res[0] == 0){
                even++;
            }
            else{
                odd++;
            }
        }
    }
    return (odd == 0 && even > 1) || (odd == 1 && even == 0) || (odd == 0 && even == 1);
    
};

    