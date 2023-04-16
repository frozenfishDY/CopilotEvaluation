/**https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/ */
//Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
//Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
//Note that you can return the indices of the edges in any order.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[][]}
 */
var findCriticalAndPseudoCriticalEdges = function(n, edges) {
    let m = edges.length;
    for(let i = 0; i < m; i++){
        edges[i].push(i);
    }
    edges.sort((a, b) => a[2] - b[2]);
    let uf = new UnionFind(n);
    let value = 0;
    for(let i = 0; i < m; i++){
        if(uf.union(edges[i][0], edges[i][1])){
            value += edges[i][2];
        }
    }
    let ans = [[], []];
    for(let i = 0; i < m; i++){
        let uf = new UnionFind(n);
        let v = 0;
        let cnt = 0;
        for(let j = 0; j < m; j++){
            if(i != j && uf.union(edges[j][0], edges[j][1])){
                v += edges[j][2];
                cnt++;
            }
        }
        if(cnt != n - 1 || (cnt == n - 1 && v > value)){
            ans[0].push(edges[i][3]);
            continue;
        }
        uf = new UnionFind(n);
        uf.union(edges[i][0], edges[i][1]);
        v = edges[i][2];
        cnt = 1;
        for(let j = 0; j < m; j++){
            if(i != j && uf.union(edges[j][0], edges[j][1])){
                v += edges[j][2];
                cnt++;
            }
        }
        if(cnt == n - 1){
            ans[1].push(edges[i][3]);
        }
    }
    return ans;
    
    
};

    