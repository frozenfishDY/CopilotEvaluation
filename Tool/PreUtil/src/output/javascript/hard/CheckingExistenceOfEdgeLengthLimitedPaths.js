/**https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/ */
//An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.
//Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .
//Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.


/**
 * @param {number} n
 * @param {number[][]} edgeList
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var distanceLimitedPathsExist = function(n, edgeList, queries) {
    let uf = new UnionFind(n);
    let m = queries.length;
    for(let i = 0; i < m; i++){
        queries[i].push(i);
    }
    edgeList.sort((a, b) => a[2] - b[2]);
    queries.sort((a, b) => a[2] - b[2]);
    let res = new Array(m);
    let idx = 0;
    for(let query of queries){
        let [a, b, limit, i] = query;
        while(idx < edgeList.length && edgeList[idx][2] < limit){
            let [x, y, dis] = edgeList[idx];
            uf.union(x, y);
            idx++;
        }
        res[i] = uf.find(a) == uf.find(b);
    }
    return res;
    
    
};

    