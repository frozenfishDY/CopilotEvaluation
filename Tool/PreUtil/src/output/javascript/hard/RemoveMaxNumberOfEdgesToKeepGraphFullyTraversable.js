/**https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/ */
//Alice and Bob have an undirected graph of n nodes and three types of edges:
//Type 1: Can be traversed by Alice only.
//Type 2: Can be traversed by Bob only.
//Type 3: Can be traversed by both Alice and Bob.
//Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
//Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var maxNumEdgesToRemove = function(n, edges) {
    let uf1 = new UnionFind(n);
    let uf2 = new UnionFind(n);
    let res = 0;
    for(let [type, u, v] of edges){
        u--;
        v--;
        if(type == 3){
            if(!uf1.union(u, v)){
                res++;
            }else{
                uf2.union(u, v);
            }
        }
    }
    for(let [type, u, v] of edges){
        u--;
        v--;
        if(type == 1){
            if(!uf1.union(u, v)){
                res++;
            }
        }else if(type == 2){
            if(!uf2.union(u, v)){
                res++;
            }
        }
    }
    if(uf1.count != 1 || uf2.count != 1){
        return -1;
    }
    return res;
    
    
};

    